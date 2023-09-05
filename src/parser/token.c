/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:55 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 15:53:49 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/parser/peek.h"
#include "../../include/parser/token.h"
#include "../../include/parser/list_token.h"
#include "../../libft/libft.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * token_create - create a new token
 * @text:	the token text (and text_aux) {the text can be NULL}
 * @type:	the token type
 *
 * Return:
 * 	On success:
 * 		a new malloc token
 * 	On failure:
 * 		NULL is returned
*/
t_token	*token_create(const char *text, t_tok_type type)
{
	t_token	*new_token;

	new_token = ft_calloc(1, sizeof(*new_token));
	if (!new_token)
		return (NULL);
	new_token->type = type;
	if (text)
	{
		new_token->text = ft_strdup(text);
		if (!new_token->text)
		{
			token_destroy(new_token);
			return (NULL);
		}
		new_token->text_aux = ft_strdup(text);
		if (!new_token->text_aux)
		{
			token_destroy(new_token);
			return (NULL);
		}
	}
	else
		new_token->text = NULL;
	return (new_token);
}

/**
 * token_destroy - frees the memory of the token structure and all its members.
*/
void	token_destroy(t_token *token_free)
{
	if (!token_free)
		return ;
	if (token_free->text)
		free(token_free->text);
	if (token_free->text_aux)
		free(token_free->text_aux);
	free(token_free);
}

/**
 * handler_many_char - create a token with one caracter
 * @stream:	a structure with the list of tokens and other information that will
 * 			be manipulated in the creation of the token.
 * @text:	the token text
 * @type:	the token type
 *
 * This function treats tokens with fixed length of text
 *
 * Return:
 *   On success:
 * 		new token
 * 	 On failure:
 * 		return NULL (malloc error!) the list doesn't change
*/
t_token	*hdl_one_char(t_stream *tok, const char *text, t_tok_type type)
{
	t_token	*token;

	token = token_create(text, type);
	tok->index++;
	return (token);
}

/**
 * handler_many_char - create a token with many caracteres
 * @stream:	a structure with the list of tokens and other information that will
 * 			be manipulated in the creation of the token.
 * @type:	the token type
 *
 * This function handlers tokens with many caracteres
 *
 * Return:
 *   On success:
 * 		new token
 * 	 On failure:
 * 		NULL (malloc error!) the list doesn't change
*/
t_token	*hdl_many_char(t_stream *stream, t_tok_type type)
{
	t_token	*token;
	size_t	count_chars;
	char	*text;

	count_chars = 0;
	while (peek(stream->line, stream->index + count_chars) == type)
		count_chars++;
	text = ft_substr(stream->line + stream->index, 0, count_chars);
	if (!text)
		return (NULL);
	token = token_create(text, type);
	free(text);
	if (!token)
		return (NULL);
	stream->index += count_chars;
	return (token);
}
