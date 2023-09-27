/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:45:30 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/26 22:05:36 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/executor/path_creator.h"
#include "../../include/executor/redirect/redirect.h"
#include "../../include/signal/signals.h"
#include "../../include/utils/message.h"
#include <unistd.h>
#include <signal.h>

static void	execute_exit(char *full_path, t_mini *mini, t_io *io, int code)
{
	if (full_path)
		free(full_path);
	if (io)
		redirect_close_io(io);
	mini_destroy(mini);
	exit(code);
}

static void	execute_exec(t_mini *mini, t_command *s_comd)
{
	int		m_status;
	char	*full_path;

	full_path = NULL;
	m_status = 0;
	if (s_comd->command_path)
		full_path = get_cmd_full_path(s_comd->command_path, \
			mini->env, &m_status);
	if (m_status)
	{
		msg_fatal_err("malloc error! get_cmd_full_path");
		execute_exit(full_path, mini, NULL, 1);
	}
	if (full_path == NULL)
	{
		ft_printf(2, "minishell: %s: command not found\n", s_comd->command_path);
		execute_exit(full_path, mini, NULL, 127);
	}
	else if (!access(full_path, F_OK) && access(full_path, X_OK))
	{
		ft_printf(2, "minishell: %s: Permission denied\n", s_comd->command_path);
		execute_exit(full_path, mini, NULL, 126);
	}
	execve(full_path, s_comd->argv, mini->env);
	msg_syscall_err(s_comd->command_path);
	execute_exit(full_path, mini, NULL, 127);
}

static void	execute_binary(t_mini *mini, t_command *s_comd)
{
	if (redirect_files(s_comd))
		execute_exit(NULL, mini, &s_comd->io, 1);
	if (redirect_dup2(&s_comd->io))
		execute_exit(NULL, mini, &s_comd->io, 1);
	if (redirect_close_io(&s_comd->io))
		execute_exit(NULL, mini, &s_comd->io, 1);
	if (s_comd->command_path)
	{
		if (is_directory(s_comd->command_path))
		{
			ft_printf(2, "minishell: %s: Is a directory\n",s_comd->command_path);
			execute_exit(NULL, mini, NULL, 126);
		}
		execute_exec(mini, s_comd);
	}
	execute_exit(NULL, mini, NULL, 0);
}

static void	execute_builtin(t_mini *mini, t_command *s_comd)
{
	int				bultin_code;
	t_builtin_func	builtin_func;

	if (redirect_files(s_comd))
		execute_exit(NULL, mini, &s_comd->io, 1);
	if (redirect_dup2(&s_comd->io))
		execute_exit(NULL, mini, &s_comd->io, 1);
	builtin_func = get_builtin(s_comd->command_path);
	bultin_code = builtin_func(&mini, s_comd->argv, s_comd->io.fd_stdout);
	if (redirect_close_io(&s_comd->io))
		execute_exit(NULL, mini, &s_comd->io, 1);
	execute_exit(NULL, mini, &s_comd->io, bultin_code);
}

void	execute_command(t_mini *mini, t_command *simple_command)
{
	int	is_builtin;

	is_builtin = 0;
	if (simple_command->command_path)
		is_builtin = (get_builtin(simple_command->command_path) != NULL);
	if (is_builtin)
		execute_builtin(mini, simple_command);
	else
		execute_binary(mini, simple_command);
}
