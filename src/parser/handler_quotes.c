/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:16 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/30 17:31:26 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser/handler_quotes.h"
#include "../../include/minishell.h"
#include "../../include/parser/token.h"
#include "../../include/parser/list_token.h"

/**
 * get_quote_status - returns a status for quote based on the current token
 * 					  type and current quote status. This status tells us if
 * 					  we are outside or inside quotes.
 *
 * these status are:
 * 		STATUS_DEFAULT - out of quotes
 * 		STATUS_DQUOTE  - inside double quotes
 * 		STATUS_SQUOTE  - inside single quotes
 *
 * Return:
 *		a quote status;
*/
int	get_quote_status(t_tok_type token_type, int quote_status)
{
	if (quote_status == STATUS_DEFAULT)
	{
		if (token_type == dquote)
			return (STATUS_DQUOTE);
		if (token_type == squote)
			return (STATUS_SQUOTE);
	}
	else
	{
		if (token_type == dquote && quote_status == STATUS_DQUOTE)
			return (STATUS_DEFAULT);
		if (token_type == squote && quote_status == STATUS_SQUOTE)
			return (STATUS_DEFAULT);
	}
	return (quote_status);
}

/**
 * check_opened_quote - checks if there open squote or dquote within the list
 * 						of tokens.
 *
 * Return:
 * 	0 if there no are open quotes
 * 	1 if are double quotes open
 *  2 if are single quotes open
*/
int	check_opened_quote(t_token *token_list)
{
	size_t	count;
	t_token	*aux;
	int		status;

	count = 0;
	aux = list_token_get(token_list, count);
	status = STATUS_DEFAULT;
	while (aux->type != eol)
	{
		status = get_quote_status(aux->type, status);
		aux = list_token_get(token_list, ++count);
	}
	return (status);
}

/**
 * add_empty_string -	add token word with an empty string after a dquote
 * 						token in STATUS_DQUOTE or squote token in STATUS_SQUOTE.
 * @token_list:	the token list
 *
 * Return:
 * 	 On success:
 * 		0
 * 	 On failure:
 * 		1 (malloc error!)
*/
int	add_empty_string(t_token **token_list)
{
	size_t	count;
	t_token	*aux;
	t_token	*empty_string;
	int		status;

	count = 0;
	aux = list_token_get(*token_list, count);
	status = STATUS_DEFAULT;
	while (aux->type != eol)
	{
		status = get_quote_status(aux->type, status);
		if ((status == STATUS_DQUOTE && aux->type == dquote)
			|| (status == STATUS_SQUOTE && aux->type == squote))
		{
			empty_string = token_create("", word);
			if (empty_string)
				list_token_add_index(token_list, empty_string, count + 1);
			else
				return (1);
		}
		aux = list_token_get(*token_list, ++count);
	}
	return (0);
}

/**
 * remove_quotes - remove squote or dquote tokens from list
 * @token_list:	list to remove the tokens
 *
 * Return:
 * 	On success:
 * 		0
 * 	On failure:
 * 		1
*/
int	remove_quotes(t_token **token_list)
{
	size_t	count;
	t_token	*aux;
	int		list_return;

	count = 0;
	aux = list_token_get(*token_list, count);
	list_return = 0;
	while (aux->type != eol)
	{
		if (aux->type == dquote || aux->type == squote)
			list_return = list_token_remove(token_list, count);
		else
			count++;
		if (list_return)
			return (list_return);
		aux = list_token_get(*token_list, count);
	}
	return (list_return);
}
