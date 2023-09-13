/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:37:03 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/13 17:37:23 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
#include "../../../include/parser/token.h"
#include "../../../include/parser/list_token.h"
#include "../../../include/parser/grammar/grammar.h"
#include "../../../include/utils/message.h"

void	print_syntax_err(t_tok_type token_type)
{
	msg_err_nnl("minishell: syntax error near unexpected token `");
	if (token_type == redir_in)
		msg_err_nnl("<");
	else if (token_type == redir_out)
		msg_err_nnl(">");
	else if (token_type == heredoc)
		msg_err_nnl("<<");
	else if (token_type == append)
		msg_err_nnl(">>");
	else if (token_type == pipez)
		msg_err_nnl("|");
	else if (token_type == eol)
		msg_err_nnl("newline");
	msg_err("\'");
}

static void	check_token_type(t_token *token, t_grammar	*grammar)
{
	if (token->type == word)
		grammar_word(token, grammar);
	else if (token->type == redir_in)
		grammar_redir_in(token, grammar);
	else if (token->type == redir_out)
		grammar_redir_out(token, grammar);
	else if (token->type == heredoc)
		grammar_heredoc(token, grammar);
	else if (token->type == append)
		grammar_append(token, grammar);
	else if (token->type == pipez)
		grammar_pipez(token, grammar);
}

/**
 * check_grammar - check the token_list syntax
 *
 * Return:
 * 	On success:
 * 		0
 *  On failure:
 * 		1 grammar syntax error
*/
int	check_grammar(t_token *token_list)
{
	t_grammar	grammar;
	t_token		*token_aux;

	grammar.count = 0;
	grammar.is_grammar_err = 0;
	token_aux = token_list;
	while (token_aux->type != eol)
	{
		check_token_type(token_aux, &grammar);
		if (grammar.is_grammar_err)
			return (1);
		token_aux = list_token_get(token_list, grammar.count);
	}
	return (0);
}
