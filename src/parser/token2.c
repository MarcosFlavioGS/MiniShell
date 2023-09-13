/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:59 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/13 17:35:03 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/parser/peek.h"
#include "../../include/parser/token.h"
#include "../../include/parser/list_token.h"
#include "../../libft/libft.h"
#include <stddef.h>
#include <stdlib.h>

t_token	*token_redir_in(t_stream *tokenize)
{
	t_token	*token;
	size_t	cnt;

	cnt = 1;
	if (peek(tokenize->line, tokenize->index + cnt) == redir_in)
		cnt++;
	if (cnt == 1)
		token = token_create("<", redir_in);
	else
		token = token_create("<<", heredoc);
	if (!token)
		return (NULL);
	tokenize->index += cnt;
	return (token);
}

t_token	*token_redir_out(t_stream *tokenize)
{
	t_token	*token;
	size_t	cnt;

	cnt = 1;
	if (peek(tokenize->line, tokenize->index + cnt) == redir_out)
		cnt++;
	if (cnt == 1)
		token = token_create(">", redir_out);
	else
		token = token_create(">>", append);
	if (!token)
		return (NULL);
	tokenize->index += cnt;
	return (token);
}

t_token	*token_eol(void)
{
	t_token	*token;

	token = token_create("\0", eol);
	if (!token)
		return (NULL);
	return (token);
}
