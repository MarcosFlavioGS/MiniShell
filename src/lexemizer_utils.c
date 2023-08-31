/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexemizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:27:09 by mflavio-          #+#    #+#             */
/*   Updated: 2023/08/30 23:35:02 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	checker(char *line)
{
	int	i;

	i = 0;
	if (line[i + 1] == line[i])
		return (TRUE);
	return (FALSE);
}

int	operator_handler(char **lexemes, char *line, int i)
{
	if (*line != '|' && checker(line))
	{
		lexemes[i] = ft_substr(line, 0, 2);
		return (2);
	}
	else
	{
		lexemes[i] = ft_substr(line, 0, 1);
		return (1);
	}
}

int	special_strlen(char *line)
{
	int	i;

	i = 0;
	while (line[i] != ' '
		&& line[i] != S_QUOTE && line[i] != D_QUOTE
		&& line[i] != REDIR_IN && line[i] != REDIR_OUT && line[i] != PIPE
		&& line[i])
		i++;
	return (i);
}
