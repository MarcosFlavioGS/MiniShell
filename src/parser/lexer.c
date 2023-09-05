/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:36 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 15:44:12 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser/lexer.h"
#include "../../include/minishell.h"
#include "../../include/parser/token.h"
#include "../../include/parser/list_token.h"
#include <stdlib.h>

/**
 * get_token2 - create a token
 * @stream:	a structure with the list of tokens and other information that will
 * 			be manipulated in the creation of the token.
 *
 * Return:
 * 	 On success:
 * 		new token
 *	 On failure:
 *		NULL (memory alloc error!)
*/
static t_token	*get_token2(t_stream *stream, char c)
{
	t_token	*new_token;

	if (c == '=')
		new_token = token_equal(stream);
	else if (c == '?')
		new_token = token_interrogation(stream);
	else
		new_token = token_word(stream);
	return (new_token);
}

/**
 * get_token - create a token
 * @stream:	a structure with the list of tokens and other information that will
 * 			be manipulated in the creation of the token.
 *
 * Return:
 * 	 On success:
 * 		new token
 *	 On failure:
 *		NULL (memory alloc error!)
*/
static t_token	*get_token(t_stream *stream, char c)
{
	t_token	*new_token;

	if ((c >= '\t' && c <= '\r') || c == ' ')
		new_token = token_separator(stream);
	else if (c == '<')
		new_token = token_redir_in(stream);
	else if (c == '>')
		new_token = token_redir_out(stream);
	else if (c == '|')
		new_token = token_pipe(stream);
	else if (c == '$')
		new_token = token_expand(stream);
	else if (c == '\0')
		new_token = token_eol(stream);
	else if (c == '\"')
		new_token = token_dquote(stream);
	else if (c == '\'')
		new_token = token_squote(stream);
	else if (c == '\0')
		new_token = token_eol(stream);
	else
		new_token = get_token2(stream, c);
	return (new_token);
}

/**
 * tokenizer - get a new token and add it to the end of the token list.
 * @stream:		the structure that is holding the string information during
 * 				tokenization.
 * @token_list: the token list to add new token
 * @c:			the current char in the string
 *
 * Return:
 * 	On success:
 * 		0 is returned
 * 	On failure:
 * 		1 is returned (malloc error!)
*/
static int	tokenizer(t_stream *stream, t_token **token_list, char c)
{
	t_token	*new_token;

	new_token = get_token(stream, c);
	if (new_token)
		list_token_add_end(token_list, new_token);
	else
	{
		list_token_clear(token_list);
		return (1);
	}
	return (0);
}

/**
 * create_tokens - create a token list.
 * @line_to_split:	line that will be used to create the tokens
 *
 * Return:
 *	On success:
 *		the token list
 *	On failure:
 *		NULL (memory alloc error!)
 */
t_token	*lexer_create_tokens(const char *line_to_split)
{
	t_stream	caracteres_stream;
	char		current_char;
	t_token		*token_list;

	caracteres_stream.line = line_to_split;
	caracteres_stream.index = 0;
	token_list = NULL;
	current_char = caracteres_stream.line[caracteres_stream.index];
	while (current_char)
	{
		if (tokenizer(&caracteres_stream, &token_list, current_char))
			return (NULL);
		current_char = caracteres_stream.line[caracteres_stream.index];
	}
	if (tokenizer(&caracteres_stream, &token_list, '\0'))
		return (NULL);
	return (token_list);
}
