/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:35:34 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/13 17:36:18 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../include/parser/parser.h"
#include "../../include/executor/executor_utils.h"
#include "../../include/minishell.h"
#include "../../include/parser/grammar/grammar.h"
#include "../../include/parser/handler_expand.h"
#include "../../include/parser/handler_quotes.h"
#include "../../include/parser/handler_squotes.h"
#include "../../include/parser/handler_dquotes.h"
#include "../../include/parser/handler_separators.h"
#include "../../include/parser/handler_word.h"
#include "../../include/parser/lexer.h"
#include "../../include/parser/list_token.h"
#include "../../include/parser/syntax_list.h"
#include "../../include/parser/token.h"
#include "../../libft/libft.h"

static int	is_token_list_created(t_mini *mini)
{
	if (!mini->token_list)
	{
		msg_fatal_err("malloc error in: lexer_create_tokens");
		return (1);
	}
	return (0);
}

int	parser(t_mini *mini, char *str_line)
{
	if (mini->token_list)
		parser_clear_mini(mini);
	mini->token_list = lexer_create_tokens(str_line);
	if (is_token_list_created(mini))
		return (1);
	if (syntax_list(mini))
	{
		parser_clear_mini(mini);
		return (1);
	}
	if (check_grammar(mini->token_list))
	{
		parser_clear_mini(mini);
		return (1);
	}
	mini->command_list = command_list_create(mini->token_list);
	if (!mini->command_list)
		return (1);
	return (0);
}

/**
 * parser_clear_mini - free the mini's token_list member and command_list
*/
void	parser_clear_mini(t_mini *mini)
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
}
