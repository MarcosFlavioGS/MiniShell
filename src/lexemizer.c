/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexemizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:53:31 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/20 18:07:32 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static int	special_strlen(char *line)
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

static int	get_next_quote(char *line)
{
	int		i;
	char	c;

	i = 0;
	c = line[i++];
	while (line[i] != c)
		i++;
	return (i);
}

static int	operator_counter(char *line, int index)
{
	if (line[index] == PIPE)
		return (1);
	else if (line[index + 1] == line[index])
		return (2);
	else
		return (1);
}

static int	token_counter(char *line)
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
		else if (line[i] == REDIR_IN || line[i] == REDIR_OUT || line[i] == PIPE)
		{
			i += operator_counter(line, i);
		}
		else
			i += special_strlen(&line[i]);
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
			lexemes[i++] = ft_substr(line, 0, get_next_quote(line) + 1);
			line += get_next_quote(line) + 1;
		}
		else if (*line == REDIR_IN || *line == REDIR_OUT || *line == PIPE)
			line += operator_handler(lexemes, line, i++);
		else if (*line)
		{
			lexemes[i++] = ft_substr(line, 0, special_strlen(line));
			line += special_strlen(line);
		}
	}
	return (lexemes);
}
