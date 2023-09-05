/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_squotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:27 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 11:21:41 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser/handler_squotes.h"
#include "../../include/parser/handler_quotes.h"
#include "../../include/minishell.h"
#include "../../include/parser/list_token.h"

/**
 * make_inside_squote_word - turns all tokens from a list of tokens inside
 * 							 single quotes into words.
 * @token_list:	the token list
*/
void	make_inside_squote_word(t_token *token_list)
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
		if (status == STATUS_SQUOTE && aux->type != squote)
				aux->type = word;
		aux = list_token_get(token_list, ++count);
	}
}
