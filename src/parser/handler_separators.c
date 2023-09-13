/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_separators.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:23 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/13 13:34:54 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser/handler_separators.h"
#include "../../include/parser/handler_quotes.h"
#include "../../include/parser/list_token.h"
#include "../../include/minishell.h"
#include <stdlib.h>

/**
 * is_to_remove2 -	check 2 tokens, one before and one after the separator,
 * 					to see if it (the separator token) should be deleted.
 * @before:	the token that is before the separator
 * @after:	the token that is after the separator
 *
 * Return:
 * 		1 if the separator is to be removed, 0 otherwise.
*/
static int	is_to_remove2(t_token *before, t_token *after)
{
	if ((before->type == dquote && after->type == dquote)
		|| (before->type == dquote && after->type == expand)
		|| (before->type == dquote && after->type == squote)
		|| (before->type == dquote && after->type == word)
		|| (before->type == squote && after->type == dquote)
		|| (before->type == squote && after->type == expand)
		|| (before->type == squote && after->type == squote)
		|| (before->type == squote && after->type == word)
		|| (before->type == word && after->type == dquote)
		|| (before->type == word && after->type == expand)
		|| (before->type == word && after->type == squote)
		|| (before->type == word && after->type == word)
		|| (before->type == expand && after->type == dquote)
		|| (before->type == expand && after->type == expand)
		|| (before->type == expand && after->type == squote)
		|| (before->type == expand && after->type == word))
		return (0);
	return (1);
}

/**
 * is_to_remove - checks whether a separator type token at a given index should
 * 				  be removed.
 * @token_list:	list to be analyzed
 * @index:		the separator token index
 * @status:		current quotes status
 *
 * Return:
 * 		1 if the separator is to be removed, 0 otherwise.
*/
static int	is_to_remove(t_token **token_list, size_t index, int status)
{
	t_token	*before;
	t_token	*actual;
	t_token	*after;

	actual = list_token_get(*token_list, index);
	if (status != STATUS_DEFAULT || actual->type != separator)
		return (0);
	before = list_token_get(*token_list, index - 1);
	after = actual->next;
	return (is_to_remove2(before, after));
}

/**
 * remove_invalid_separators - remove tokens to type separators that are
 * 							   between two tokens where they (separators)
 * 							   are not needed.
 * @token_list:	list to be analyzed
*/
void	remove_invalid_separators(t_token **token_list)
{
	size_t	count;
	t_token	*aux;
	int		status;

	count = 0;
	aux = *token_list;
	status = STATUS_DEFAULT;
	if (aux->type == separator)
	{
		list_token_remove(token_list, 0);
		aux = list_token_get(*token_list, count);
	}
	while (aux->type != eol)
	{
		status = get_quote_status(aux->type, status);
		if (is_to_remove(token_list, count, status) == 1)
			list_token_remove(token_list, count);
		else
			count++;
		aux = list_token_get(*token_list, count);
	}
}

/**
 * remove_separators - remove all separators from the list
 * @token_list: the token list to remove the separators
 *
 * Return:
 * 	On success:
 * 		0
 * 	On failure:
 * 		1
*/
int	remove_separators(t_token **token_list)
{
	size_t	count;
	t_token	*aux;
	int		list_return;

	count = 0;
	aux = list_token_get(*token_list, count);
	list_return = 0;
	while (aux->type != eol)
	{
		if (aux->type == separator)
			list_return = list_token_remove(token_list, count);
		else
			count++;
		if (list_return)
			return (list_return);
		aux = list_token_get(*token_list, count);
	}
	return (list_return);
}
