/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:08:09 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/13 18:36:30 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser/token.h"
#include "../../include/minishell.h"

t_token	*token_interrogation(t_stream *tokenize)
{
	return (hdl_one_char(tokenize, "?", word));
}
