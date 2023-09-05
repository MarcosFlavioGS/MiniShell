/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:08:09 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 11:39:13 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/parser/list_token.h"
#include "../../include/parser/token.h"
#include "../../include/parser/peek.h"

t_token	*token_interrogation(t_stream *tokenize)
{
	return (hdl_one_char(tokenize, "?", word));
}
