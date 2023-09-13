/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:44 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 15:46:25 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser/peek.h"
#include "../../include/minishell.h"
#include <stddef.h>

/**
 * peek - returns a type of token based on the current character in the string.
 * @str: 	the string
 * @index:	current string caracter
 *
 * Return:
 * 		a token type
*/
t_tok_type	peek(const char *str, size_t index)
{
	if ((str[index] >= '\t' && str[index] <= '\r') || (str[index] == ' '))
		return (separator);
	if (str[index] == '<')
		return (redir_in);
	if (str[index] == '>')
		return (redir_out);
	if (str[index] == '|')
		return (pipez);
	if (str[index] == '$')
		return (expand);
	if (str[index] == '\"')
		return (dquote);
	if (str[index] == '\'')
		return (squote);
	if (str[index] == '=')
		return (equal);
	if (str[index] == '?')
		return (interrogation);
	if (str[index] == '\0')
		return (eol);
	return (word);
}
