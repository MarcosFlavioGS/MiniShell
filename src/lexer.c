/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:22:03 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/27 22:25:49 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static void get_type(char **identifier, enum Type *type)
{
	if (!ft_strncmp(*identifier, "<<", 2) && ft_strlen(*identifier) == 2)
		*type = heredoc;
	else if (!ft_strncmp(*identifier, ">>", 2) && ft_strlen(*identifier) == 2)
		*type = append;
	else if (!ft_strncmp(*identifier, ">", 1) && ft_strlen(*identifier) == 1)
		*type = redir_out;
	else if (!ft_strncmp(*identifier, "<", 1) && ft_strlen(*identifier) == 1)
		*type = redir_in;
	else if (!ft_strncmp(*identifier, "|", 1) && ft_strlen(*identifier) == 1)
		*type = t_pipe;
	else if (!ft_strncmp(*identifier, " ", 1) && ft_strlen(*identifier) == 1)
		*type = separator;
	else
		*type = word;
}

static t_token	*new_token(char *identifier)
{
	t_token	*token;
	enum Type type;

	token = malloc(sizeof(t_token));
	token->t_name = malloc(ft_strlen(identifier) + 1);
	if (*identifier == S_QUOTE || *identifier == D_QUOTE)
		ft_strlcpy(token->t_name, identifier + 1, ft_strlen(identifier) - 1);
	else
		ft_strlcpy(token->t_name, identifier, ft_strlen(identifier) + 1);
	token->t_name[ft_strlen(identifier)] = '\0';
	get_type(&token->t_name, &type);
	token->at_value = hash(token->t_name, 15);
	token->type = type;
	token->expand = FALSE;
	return (token);
}

static void	free_array(char **array)
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

static int check_null_str(char s1, char s2, int *i)
{
	if ((s1 == S_QUOTE || s2 == D_QUOTE)
		&& s1 == s2)
		{
			*i += 1;
			return (1);
		}
	return (0);
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
		if (check_null_str(lexemes[i][0], lexemes[i][1], &i))
			continue ;
		token = new_token(lexemes[i]);
		new_tokenized = malloc(sizeof(t_tokenized));
		new_tokenized->token = token;
		new_tokenized->next = NULL;
		if (lexemes[i][0] != S_QUOTE)
			new_tokenized->token->expand = TRUE;
		if (!*tokens)
			*tokens = new_tokenized;
		else
			current->next = new_tokenized;
		current = new_tokenized;
		i++;
	}
}

void	lexer(t_mini **mini, char *line, t_tokenized **tokens)
{
	char		**lexeme_array;

	lexeme_array = lexemizer(line);
	tokenize(lexeme_array, tokens);
	expand((*mini)->env_table, tokens);
	free_array(lexeme_array);
}
