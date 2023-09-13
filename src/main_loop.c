/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:14:05 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/13 17:50:51 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/parser/parser.h"
#include "../include/parser/list_token.h"
#include "../include/executor/executor_utils.h"

//debug
#include "../debug/executor/simple_command_debug.h"

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

	while (1)
	{
		mini->line = get_line();
		if (!mini->line)
			exit_shell(mini);
		parser_status = parser(mini, mini->line);
		if (parser_status)
			exit_shell(mini);
		else
			simple_command_list_printf_nl(mini->command_list);
		main_loop_clear(mini);
	}
}
