/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:51 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/26 19:44:23 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser/syntax_list.h"
#include "../../include/minishell.h"
#include "../../include/parser/handler_expand.h"
#include "../../include/parser/handler_quotes.h"
#include "../../include/parser/handler_squotes.h"
#include "../../include/parser/handler_dquotes.h"
#include "../../include/parser/handler_separators.h"
#include "../../include/parser/handler_word.h"
#include "../../include/parser/lexer.h"
#include "../../include/parser/list_token.h"
#include "../../include/parser/parser.h"
#include "../../include/parser/token.h"
#include "../../include/utils/message.h"
#include "../../libft/libft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static int	is_quotes_opened(t_token *token_list)
{
	int	returnz;
	int	quotes_status;

	returnz = 0;
	quotes_status = check_opened_quote(token_list);
	if (quotes_status == STATUS_SQUOTE)
	{
		msg_err("minishell: line 0: "
			"unexpected EOF while looking for matching `''");
		returnz = 1;
	}
	if (quotes_status == STATUS_DQUOTE)
	{
		msg_err("minishell: line 0: "
			"unexpected EOF while looking for matching `\"'");
		returnz = 1;
	}
	if (returnz)
		msg_err("minishell: line 1: syntax error: unexpected end of file");
	return (returnz);
}

/**
 *
 * Return:
 * 	On success:
 * 		0 is returned
 * 	On failure:
 * 		1 is returned
*/
static int	the_quotes(t_token *token_list)
{
	make_inside_squote_word(token_list);
	make_inside_dquote_word(token_list);
	if (add_empty_string(&token_list))
	{
		msg_fatal_err("malloc error in: add_empty_string method");
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
static int	the_expand(t_mini *mini)
{
	remove_invalid_separators(&mini->token_list);
	remove_invalid_expand(&mini->token_list);
	make_invalid_expand_word(&mini->token_list);
	make_expand_after_heredoc_word(&mini->token_list);
	if (join_expand_with_word(&mini->token_list))
	{
		msg_fatal_err("malloc error in: join_expand_with_word");
		return (1);
	}
	if (make_expand(&mini->token_list, mini))
	{
		msg_fatal_err("malloc error in: make_expand");
		return (1);
	}
	return (0);
}

/**
 * syntax_list - create a token list to the grammar.
 * @mini:		the program struct
 * @str_line:	the input line to create the tokens
 *
 * Return:
 * 	On success:
 * 		0 is returned:
 * 	On failure:
 * 		1 On simple syntax errors
*/
int	syntax_list(t_mini *mini)
{
	if (is_quotes_opened(mini->token_list))
		return (1);
	if (the_quotes(mini->token_list))
		return (1);
	if (the_expand(mini))
		return (1);
	if (remove_quotes(&mini->token_list))
	{
		msg_fatal_err("malloc error in: remove_quotes");
		return (1);
	}
	if (join_words(&mini->token_list))
	{
		msg_fatal_err("malloc error in: join_words");
		return (1);
	}
	if (remove_separators(&mini->token_list))
	{
		msg_fatal_err("malloc error in: remove_separators");
		return (1);
	}
	return (0);
}
