/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexemizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:53:31 by mflavio-          #+#    #+#             */
/*   Updated: 2023/05/17 12:30:47 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int	special_strlen(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i] != c && line[i])
		i++;
	return (i);
}

int	get_next_quote(char *line)
{
	int		i;
	char	c;

	i = 0;
	c = line[i++];
	while (line[i] != c)
		i++;
	return (i);
}

int	token_counter(char *line)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == S_QUOTE || line[i] == D_QUOTE)
		{
			i += get_next_quote(&line[i]);
			i++;
		}
		else
		{
			i += special_strlen(&line[i], ' ');
		}
		count++;
	}
	return (count);
}

char	**lexemizer(char *line)
{
	int		i;
	int		count;
	char	**lexemes;

	i = 0;
	count = token_counter(line);
	lexemes = (char **)ft_calloc(count + 1, sizeof(char *));
	while (*line)
	{
		while (*line == ' ')
			line++;
		if (*line == S_QUOTE || *line == D_QUOTE)
		{
			lexemes[i] = ft_substr(line, 0, get_next_quote(line) + 1);
			i++;
			line += get_next_quote(line) + 1;
		}
		else
		{
			lexemes[i] = ft_substr(line, 0, special_strlen(line, ' '));
			i++;
			line += special_strlen(line, ' ');
		}
	}
	return (lexemes);
}
