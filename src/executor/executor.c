/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:25:54 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/25 14:42:41 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor/executor.h"
#include "../../include/executor/heredoc_manager.h"
#include "../../include/executor/path_creator.h"
#include "../../include/executor/redirect/redirect.h"
#include "../../include/utils/message.h"
#include "../../include/executor/pipeline.h"

static void	execute_builtin_in_parent(t_mini *mini)
{
	int				bultin_code;
	t_builtin_func	builtin_func;
	t_command		*s_comd;

	s_comd = mini->command_list;
	if (redirect_files(s_comd))
	{
		mini->last_exit_code = 1;
		return ;
	}
	builtin_func = get_builtin(s_comd->command_path);
	bultin_code = builtin_func(&mini, s_comd->argv, s_comd->io.fd_stdout);
	if (redirect_close_io(&s_comd->io))
		bultin_code = 1;
	mini->last_exit_code = bultin_code;
}

void	executor(t_mini *mini)
{
	int				heredoc_status;
	int				is_builtin;
	t_builtin_func	fun_builtin;

	heredoc_status = make_all_heredocs(mini);
	if (heredoc_status)
		return ;
	fun_builtin = get_builtin(mini->command_list->command_path);
	is_builtin = (mini->command_list->command_path && fun_builtin \
		&& !mini->command_list->next);
	if (is_builtin)
		execute_builtin_in_parent(mini);
	else
		execute_pipeline(mini);
}
