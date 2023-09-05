/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:51 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 17:03:14 by dmanoel-         ###   ########.fr       */
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
#include "../../include/parser/token.h"
#include "../../include/utils/die.h"
#include "../../include/utils/message.h"
#include "../../libft/libft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static int	is_token_list_created(t_mini *mini)
{
	if (!mini->token_list)
	{
		msg_err("malloc error in: lexer_create_tokens");
		return (1);
	}
	return (0);
}

static int	is_quotes_opened(t_mini *mini)
{
	int	returnz;
	int	quotes_status;

	returnz = 0;
	quotes_status = check_opened_quote(mini->token_list);
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

static void	the_quotes(t_mini *mini)
{
	make_inside_squote_word(mini->token_list);
	make_inside_dquote_word(mini->token_list);
	if (add_empty_string(&mini->token_list))
		die(mini, "malloc error in: add_empty_string method");
}

static void	the_expand(t_mini *mini)
{
	remove_invalid_separators(&mini->token_list);
	remove_invalid_expand(&mini->token_list);
	make_invalid_expand_word(&mini->token_list);
	make_expand_after_heredoc_word(&mini->token_list);
	if (join_expand_with_word(&mini->token_list))
		die(mini, "malloc error in: join_expand_with_word");
	if (make_expand(&mini->token_list, mini))
		die(mini, "malloc error in: make_expand");
}

/**
 * syntax_list - create a token list to the grammar. The list may be null if an
 * 				 errors occurred.
 * @mini:		the program struct
 * @str_line:	the input line to create the tokens
*/
void	syntax_list(t_mini *mini, char *str_line)
{
	if (mini->token_list)
		syntax_list_clear_mini(mini);
	mini->token_list = lexer_create_tokens(str_line);
	if (is_token_list_created(mini))
		return ;
	if (is_quotes_opened(mini))
	{
		syntax_list_clear_mini(mini);
		return ;
	}
	the_quotes(mini);
	the_expand(mini);
	if (remove_quotes(&mini->token_list))
		die(mini, "malloc error in: remove_quotes");
	if (join_words(&mini->token_list))
		die(mini, "malloc error in: join_words");
	if (remove_separators(&mini->token_list))
		die(mini, "malloc error in: remove_separators");
}
