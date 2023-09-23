/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:19:43 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/22 21:50:11 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor/pipeline.h"
#include "../../include/executor/execute_child.h"
#include "../../include/minishell.h"
#include "../../include/utils/syscall.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 *
 * Return:
 * 	On success:
 * 		0 is returned
 * 	On failure:
 * 		1 is returned
*/
int		create_pipe(t_pipeline	*pipeline)
{
	if (pipeline->simple_command->next)
	{
		if(syscall_pipe(pipeline->pipe, "pipeline: create_pipe"))
			return (1);
	}
	return (0);
}

/**
 *
 * Return:
 * 	On success:
 * 		0 is returned
 * 	On failure:
 * 		1 is returned
*/
int		create_fork(t_pipeline	*pipeline, t_mini *mini)
{
	pipeline->simple_command->pid = syscall_fork("pipeline: create_fork");
	if (pipeline->simple_command->pid == -1)
	{
		printf("tratar deu pau");
		return (1);
	}
	if (pipeline->simple_command->pid)
	{
		if (pipeline->count_child > 0)
			syscall_close(pipeline->tmp_fd_in, "pipeline: close temp_fd_in");
		pipeline->tmp_fd_in = pipeline->pipe[IN];
		if (pipeline->simple_command->next)
			syscall_close(pipeline->pipe[OUT], "pipeline: close pipe[OUT]");
	}
	else
	{
		if (pipeline->simple_command->next)
			syscall_close(pipeline->pipe[IN], "pipeline: close pipe[IN]");
		execute_command(mini, pipeline->simple_command);
	}
	return (0);
}

void	wait_children(t_mini *mini, t_pipeline	*pipeline)
{
	pid_t	wpid;
	int		status;
	int		last_status;

	last_status = 0;
	wpid = 0;
	while (wpid != -1 || errno != ECHILD)
	{
		wpid = waitpid(-1, &status, 0);
		if (wpid == pipeline->simple_command->pid)
			last_status = status;
		continue ;
	}
	if (WIFSIGNALED(last_status))
		mini->last_exit_code = 128 + WTERMSIG(last_status);
	else if (WIFEXITED(last_status))
		mini->last_exit_code = WEXITSTATUS(last_status);
	else
		mini->last_exit_code = last_status;
	if (!pipeline->is_sucessfull)
		mini->last_exit_code = 1;
}

void	execute_pipeline(t_mini *mini)
{
	t_pipeline	pipeline;

	pipeline.tmp_fd_in = 0;
	pipeline.simple_command = mini->command_list;
	pipeline.count_child = 0;
	pipeline.is_sucessfull = 1;
	while (pipeline.simple_command)
	{
		if (create_pipe(&pipeline))
		{
			pipeline.is_sucessfull = 0;
			break ;
		}
		pipeline.simple_command->io.fd_stdin = pipeline.tmp_fd_in;
		if (pipeline.simple_command->next)
			pipeline.simple_command->io.fd_stdout = pipeline.pipe[OUT];
		if (create_fork(&pipeline, mini))
		{
			pipeline.is_sucessfull = 0;
			break ;
		}
		if (!pipeline.simple_command->next)
			break ;
		pipeline.count_child++;
		pipeline.simple_command = pipeline.simple_command->next;
	}
	wait_children(mini, &pipeline);
}
