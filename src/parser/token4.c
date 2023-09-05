/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:08:06 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 11:23:04 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/parser/list_token.h"
#include "../../include/parser/token.h"
#include "../../include/parser/peek.h"
#include "../../libft/libft.h"

t_token	*token_separator(t_stream *stream)
{
	return (hdl_many_char(stream, separator));
}

t_token	*token_word(t_stream *stream)
{
	return (hdl_many_char(stream, word));
}
