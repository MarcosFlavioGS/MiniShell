/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:37:58 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/25 09:30:45 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor/heredoc_manager.h"
#include "../../include/utils/syscall.h"
#include "../../include/minishell.h"
#include "../../include/executor/redirect/heredoc.h"
#include "../../include/signal/signals.h"
#include "../../include/utils/global_config.h"

#define HDOC_MANAGER_ERR1 "heredoc_manager[HDOC_MANAGER_ERR1]"

/**
 *
 * Return:
 * 	On success:
 * 		0 is returned
 * 	On failure:
 * 		1 is returned
*/
static int	prepare_hdoc(t_redirect *redirect)
{
	int	input_backup;

	if (redirect->type != heredoc)
		return (0);
	input_backup = syscall_dup(0, "prepare_hdoc: input_backup");
	if (input_backup == -1)
		return (1);
	set_signals_heredoc();
	redirect->hdoc_fd = make_heredoc(redirect->text);
	if (!get_heredoc_config())
	{
		if (syscall_dup2(input_backup, 0, "prepare_hdoc reset input") == -1)
			return (1);
	}
	if (syscall_close(input_backup, "prepare_hdoc close input_backup") == -1)
		return (1);
	if (redirect->hdoc_fd == -1 || !get_heredoc_config())
		return (1);
	return (0);
}

static int	close_hdoc(t_redirect *redirect)
{
	if (redirect->type != heredoc || redirect->hdoc_fd == -1)
		return (0);
	if (syscall_close(redirect->hdoc_fd, HDOC_MANAGER_ERR1) == -1)
		return (1);
	redirect->hdoc_fd = -1;
	return (0);
}

static int	iterator_redirect(t_redirect *redir_list, int (*f)(t_redirect *r))
{
	t_redirect	*aux_redirect;

	aux_redirect = redir_list;
	while (aux_redirect)
	{
		if (aux_redirect->type == heredoc)
			if (f(aux_redirect))
				return (1);
		aux_redirect = aux_redirect->next;
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
int	make_all_heredocs(t_mini *mini)
{
	t_command	*aux_command;
	t_command	*command_list;
	int			is_success;

	command_list = mini->command_list;
	aux_command = command_list;
	enable_heredoc_config();
	is_success = 0;
	while (aux_command && get_heredoc_config())
	{
		if (iterator_redirect(aux_command->redir_list, prepare_hdoc))
		{
			close_all_heredocs(command_list);
			is_success = 1;
			break ;
		}
		aux_command = aux_command->next;
	}
	if (get_heredoc_config() == 0)
	{
		close_all_heredocs(command_list);
		mini->last_exit_code = 130;
		is_success = 1;
	}
	return (is_success);
}

void	close_all_heredocs(t_command *command_list)
{
	t_command	*aux_command;

	aux_command = command_list;
	while (aux_command)
	{
		iterator_redirect(command_list->redir_list, close_hdoc);
		aux_command = aux_command->next;
	}
}
