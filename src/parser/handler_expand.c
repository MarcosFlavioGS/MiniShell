/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:05:43 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 15:23:02 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser/handler_expand.h"
#include "../../include/minishell.h"
#include "../../include/parser/list_token.h"
#include "../../include/parser/handler_quotes.h"

static int	is_inside_heredoc(t_token *token)
{
	if (token->type == word
		|| token->type == heredoc
		|| token->type == expand
		|| token->type == dquote
		|| token->type == squote)
		return (1);
	return (0);
}

static void	is_make_expand_to_word(t_token *token_expad, int status)
{
	char	*text;

	text = NULL;
	if (token_expad->next->type != word)
		token_expad->type = word;
	else
		text = token_expad->next->text;
	if (text && text[0] == '=')
		token_expad->type = word;
}

/**
 * make_invalid_expand_word - make invalid expansions into words
 * @token_list:	list to be analyzed
*/
void	make_invalid_expand_word(t_token **token_list)
{
	size_t	count;
	t_token	*aux;
	int		status;

	count = 0;
	aux = list_token_get(*token_list, count);
	status = STATUS_DEFAULT;
	while (aux->type != eol)
	{
		status = get_quote_status(aux->type, status);
		if (aux->type == expand && status == STATUS_DEFAULT)
			is_make_expand_to_word(aux, status);
		aux = list_token_get(*token_list, ++count);
	}
}

/**
 * remove_invalid_expand - 	remove invalids from expand list.
 * @token_list:	list to be analyzed
 *
 * An expansion token is invalid if after it there is a squote or squote token
 * and before it there was no expansion token. Examples (token list):
 * 			BEFORE			  |       AFTER
 *  word|expand|squote        |  word|squote
 *  expand|expand|squote      |  expand|expand|squote
 *
 */
void	remove_invalid_expand(t_token **token_list)
{
	size_t	count;
	t_token	*token_actual;
	t_token	*token_previous;
	int		status;

	count = 0;
	token_actual = list_token_get(*token_list, count);
	token_previous = NULL;
	status = STATUS_DEFAULT;
	while (token_actual->type != eol)
	{
		status = get_quote_status(token_actual->type, status);
		if (status == STATUS_DEFAULT && token_actual->type == expand)
		{
			if (count > 0)
				token_previous = list_token_get(*token_list, count - 1);
			if (token_previous != NULL && token_previous->type != expand)
				token_previous = NULL;
			if ((token_actual->next->type == dquote
					|| token_actual->next->type == squote)
				&& token_previous == NULL)
				list_token_remove(token_list, count--);
		}
		token_actual = list_token_get(*token_list, ++count);
	}
}

/**
 * make_expand_after_heredoc_word - transform the expand-type tokens after a
 * 									heredoc-type token into word-type tokens.
 * @token_list:	list to be analyzed
 *
 * Transform the expand-type tokens after a heredoc-type token into word-type
 * tokens. This transformation is interrupted when some types of tokens are
 * contracted.
*/
void	make_expand_after_heredoc_word(t_token **token_list)
{
	size_t	count;
	t_token	*aux;
	int		is_heredoc;

	count = 0;
	aux = list_token_get(*token_list, count);
	while (aux->type != eol)
	{
		is_heredoc = (aux->type == heredoc);
		if (is_heredoc)
		{
			while (is_inside_heredoc(aux))
			{
				if (aux->type == expand)
					aux->type = word;
				aux = list_token_get(*token_list, ++count);
			}
			if (aux->type == eol)
				break ;
		}
		aux = list_token_get(*token_list, ++count);
	}
}
