/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:22:03 by mflavio-          #+#    #+#             */
/*   Updated: 2023/05/08 18:22:06 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static t_token	*new_token(char *content, int type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->content = malloc(ft_strlen(content) + 1);
	ft_strlcpy(token->content, content, ft_strlen(content) + 1);
	token->type = type;
	token->content[ft_strlen(content)] = '\0';
	return (token);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	lexer(char *line, t_tokenized **tokens)
{
	t_token		*token;
	t_tokenized	*current;
	char		**token_array;
	int			i;

	i = 0;
	token_array = ft_split(line, ' ');
	token = new_token(token_array[i++], 0);
	*tokens = malloc(sizeof(t_tokenized));
	(*tokens)->token = token;
	(*tokens)->next = NULL;
	current = *tokens;
	while (token_array[i])
	{
		token = new_token(token_array[i], 0);
		current->next = malloc(sizeof(t_tokenized));
		current->next->token = token;
		current->next->next = NULL;
		current = current->next;
		i++;
	}
	free_array(token_array);
}
