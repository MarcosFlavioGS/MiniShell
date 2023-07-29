/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:22:03 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/28 22:05:13 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static void	get_type(char **identifier, enum Type *type)
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
	t_token		*token;
	enum Type	type;

	token = malloc(sizeof(t_token));
	token->t_name = malloc(ft_strlen(identifier) + 1);
	if (*identifier == S_QUOTE || *identifier == D_QUOTE)
	{
		if (*identifier == D_QUOTE)
			token->quote = DQUOTE;
		else
			token->quote = SQUOTE;
		ft_strlcpy(token->t_name, identifier + 1, ft_strlen(identifier) - 1);
	}
	else
	{
		token->quote = NOQUOTE;
		ft_strlcpy(token->t_name, identifier, ft_strlen(identifier) + 1);
	}
	token->t_name[ft_strlen(identifier)] = '\0';
	get_type(&token->t_name, &type);
	token->type = type;
	token->at_value = hash(token->t_name, 15);
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

static void	tokenize(char **lexemes, t_tokenstream **tokens)
{
	t_token			*token;
	t_tokenstream	*current;
	t_tokenstream	*new_tokenized;
	int				i;

	i = 0;
	new_tokenized = NULL;
	current = NULL;
	while (lexemes[i])
	{
		if (check_null_str(lexemes[i][0], lexemes[i][1], &i))
			continue ;
		token = new_token(lexemes[i]);
		new_tokenized = malloc(sizeof(t_tokenstream));
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

void	lexer(char *line, t_tokenstream **tokens)
{
	char	**lexeme_array;

	lexeme_array = lexemizer(line);
	tokenize(lexeme_array, tokens);
	free_array(lexeme_array);
}
