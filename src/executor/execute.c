/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:45:30 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/25 10:27:36 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	execute_exit(char *full_path, t_mini *mini, t_io *io, int code)
{
	if(full_path)
		free(full_path);
	if(io)
		redirect_close_io(io);
	mini_destroy(mini);
	exit(code);
}

static void execute_exec(t_mini *mini, t_command *s_comd)
{
	int		m_status = 0;
	char	*full_path;

	full_path = get_cmd_full_path(s_comd->command_path, mini->env, &m_status);
	if (m_status)
	{
		msg_fatal_err("malloc error! get_cmd_full_path");
		execute_exit(full_path, mini, NULL, 1);
	}
	if (full_path == NULL)
	{
		ft_printf(1, "minishell: %s: command not found", s_comd->command_path);
		execute_exit(full_path, mini, NULL, 127);
	}
	execpv(s_comd->command_path, s_comd->argv, mini->env);
	msg_syscall_err(s_comd->command_path);
	if (full_path)
		free(full_path);
}

static void	execute_binary(t_mini *mini, t_command *simple_command)
{
	if (redirect_files(simple_command))
		execute_exit(NULL, mini, &simple_command->io, 1);
	if (redirect_dup2(&simple_command->io))
		execute_exit(NULL, mini, &simple_command->io, 1);
	if (redirect_close_io(&simple_command->io))
		execute_exit(NULL, mini, &simple_command->io, 1);
	if (simple_command->command_path)
		execute_exec(mini, simple_command);
	execute_exit(NULL, mini, NULL, 127);
}

static int	execute_builtin(t_mini *mini, t_command *s_comd)
{
	int				bultin_code;
	t_builtin_func	builtin_func;

	if (redirect_files(s_comd))
		execute_exit(NULL, mini, &s_comd->io, 1);
	if (redirect_dup2(&s_comd->io))
		execute_exit(NULL, mini, &s_comd->io, 1);

	builtin_func = get_builtin(s_comd->command_path);

	bultin_code = builtin_func(&mini, s_comd->argv, s_comd->io.stdout);

	if (redirect_close_io(&s_comd->io))
		execute_exit(NULL, mini, &s_comd->io, 1);
	execute_exit(NULL, mini, &s_comd->io, bultin_code);
}

void	execute_command(t_mini *mini, t_command *simple_command)
{
	int	is_builtin;
	set_default_signals();
	is_builtin = (get_builtin(simple_command->command_path) != NULL);
	if(is_builtin)
		execute_builtin(mini, simple_command);
	else
		execute_binary(mini, simple_command);
}