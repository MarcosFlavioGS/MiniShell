/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:14:05 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/25 11:42:55 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/parser/parser.h"
#include "../include/parser/list_token.h"
#include "../include/executor/executor.h"
#include "../include/executor/executor_utils.h"
#include "../include/executor/heredoc_manager.h"
#include "../include/signal/signals.h"
#include "../include/utils/global_config.h"

/**
 * main_loop_clear - free unnecessay malloc to next commandline
*/
static void	main_loop_clear(t_mini *mini)
{
	if (!mini)
		return ;
	if (mini->token_list)
	{
		list_token_clear(&mini->token_list);
		mini->token_list = NULL;
	}
	if (mini->command_list)
	{
		close_all_heredocs(mini->command_list);
		command_list_destroy(mini->command_list);
		mini->command_list = NULL;
	}
	if (mini->line)
	{
		free(mini->line);
		mini->line = NULL;
	}
}

void	main_loop(t_mini *mini)
{
	int		parser_status;

	mini->last_exit_code = 0;
	while (1)
	{
		set_signals_interative();
		enable_redisplay();
		mini->line = get_line();
		if (!mini->line)
			ft_exit(&mini, NULL, 1);
		parser_status = parser(mini, mini->line);
		if (parser_status)
			mini->last_exit_code = 2;
		else
			executor(mini);
		main_loop_clear(mini);
	}
}
