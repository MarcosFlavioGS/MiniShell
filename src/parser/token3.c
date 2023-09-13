/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:08:02 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 11:23:44 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/parser/list_token.h"
#include "../../include/parser/token.h"
#include "../../include/parser/peek.h"

t_token	*token_pipe(t_stream *tokenize)
{
	return (hdl_one_char(tokenize, "|", pipez));
}

t_token	*token_expand(t_stream *tokenize)
{
	return (hdl_one_char(tokenize, "$", expand));
}

t_token	*token_dquote(t_stream *tokenize)
{
	return (hdl_one_char(tokenize, "\"", dquote));
}

t_token	*token_squote(t_stream *tokenize)
{
	return (hdl_one_char(tokenize, "\'", squote));
}

t_token	*token_equal(t_stream *tokenize)
{
	return (hdl_one_char(tokenize, "=", word));
}
