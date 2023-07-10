/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:22:03 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/09 22:26:09 by mflavio-         ###   ########.fr       */
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

static void	tokenize(char **lexemes, t_tokenized **tokens)
{
	t_token		*token;
	t_tokenized	*current;
	t_tokenized	*new_tokenized;
	int			i;

	i = 0;
	new_tokenized = NULL;
	current = NULL;
	while (lexemes[i])
	{
		token = new_token(lexemes[i], hash(lexemes[i]));
		new_tokenized = malloc(sizeof(t_tokenized));
		new_tokenized->token = token;
		new_tokenized->next = NULL;
		if (!*tokens)
			*tokens = new_tokenized;
		else
			current->next = new_tokenized;
		current = new_tokenized;
		i++;
	}
}

void	lexer(char *line, t_tokenized **tokens)
{
	char		**lexeme_array;

	lexeme_array = lexemizer(line);
	tokenize(lexeme_array, tokens);
	//separate_operators(tokens);
	print(&*tokens);
	free_array(lexeme_array);
}
