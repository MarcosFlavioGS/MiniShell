/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexemizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:27:09 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/14 00:27:16 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

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
