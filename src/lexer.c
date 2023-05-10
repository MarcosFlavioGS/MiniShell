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

static t_token	*new_token(char *identifier, unsigned int at_value)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->t_name = malloc(ft_strlen(identifier) + 1);
	ft_strlcpy(token->t_name, identifier, ft_strlen(identifier) + 1);
	token->at_value = at_value;
	token->t_name[ft_strlen(identifier)] = '\0';
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

void	print(t_tokenized **tokens)
{
	t_tokenized	*tmp;

	tmp = *tokens;
	while (tmp)
	{
		printf("Token name: %s\nSymbol id: %d\n",
			tmp->token->t_name, tmp->token->at_value);
		tmp = tmp->next;
	}
}

void	lexer(char *line, t_tokenized **tokens)
{
	t_token		*token;
	t_tokenized	*current;
	char		**lexeme_array;
	int			i;

	i = 0;
	lexeme_array = ft_split(line, ' ');
	token = new_token(lexeme_array[i], hash(lexeme_array[i]));
	*tokens = malloc(sizeof(t_tokenized));
	(*tokens)->token = token;
	(*tokens)->next = NULL;
	current = *tokens;
	while (lexeme_array[++i])
	{
		token = new_token(lexeme_array[i], hash(lexeme_array[i]));
		current->next = malloc(sizeof(t_tokenized));
		current->next->token = token;
		current->next->next = NULL;
		current = current->next;
	}
	print(&*tokens);
	free_array(lexeme_array);
}
