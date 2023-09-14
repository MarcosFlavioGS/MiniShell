/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:39:08 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/14 08:33:59 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor/simple_command.h"
#include "../../include/minishell.h"
#include "../../include/parser/list_token.h"
#include "../../include/parser/token.h"
#include "../../include/executor/string_array.h"

/**
 * add_word - add the command or add a new argument to the argv
 *
 * Return:
 * 	On success:
 * 		1 is retuned:
 * 	On failure:
 * 		0 (malloc error!)
*/
static int	add_word(t_command *simple_command, t_token *token)
{
	char	*new_word;
	char	*new_word_2;

	if (!token->text)
		return (1);
	new_word = ft_strdup(token->text);
	if (!new_word)
		return (0);
	if (simple_command->command_path)
	{
		if (string_array_add(&(simple_command->argv), new_word))
			return (0);
	}
	else
	{
		simple_command->command_path = new_word;
		new_word_2 = ft_strdup(token->text);
		if (!new_word_2)
			return (0);
		if (string_array_add(&(simple_command->argv), new_word_2))
			return (0);
	}
	return (1);
}

/**
 * add_redirect -
 *
 * Return:
 * 	On success:
 * 		1 is retuned:
 * 	On failure:
 * 		0 (malloc error!)
*/
static int	add_redirect(t_command *simple_command, t_token *token)
{
	t_token	*new_token;

	new_token = token_dup(token->next);
	if (new_token)
	{
		new_token->type = token->type;
		list_token_add_end(&simple_command->redir_list, new_token);
		return (1);
	}
	return (0);
}

/**
 * add_redirect -
 *
 * Return:
 * 	On success:
 * 		1 is retuned:
 * 	On failure:
 * 		0 (malloc error!)
*/
static int	command_create2(t_command *sc, t_token *aux, size_t *count)
{
	int	add_return;

	(*count)++;
	if (aux->type == word)
		add_return = add_word(sc, aux);
	else
	{
		add_return = add_redirect(sc, aux);
		(*count)++;
	}
	return (add_return);
}

/**
 * command_create -
 *
 * Return:
 * 	On success:
 * 		a command is returned
 * 	On failure:
 * 		NULL is returned (malloc error!)
*/
t_command	*command_create(t_token *token_list, size_t *count)
{
	t_token		*aux;
	t_command	*simple_command;
	int			add_return;

	add_return = 1;
	simple_command = ft_calloc(1, sizeof(*simple_command));
	if (!simple_command)
		return (NULL);
	simple_command->io.stdin = 0;
	simple_command->io.stdout = 1;
	aux = list_token_get(token_list, *count);
	while (aux->type != eol && aux->type != pipez && add_return)
	{
		add_return = command_create2(simple_command, aux, count);
		aux = list_token_get(token_list, *count);
	}
	if (aux->type == pipez)
		(*count)++;
	if (!add_return)
	{
		command_destroy(simple_command);
		return (NULL);
	}
	return (simple_command);
}

void	command_destroy(t_command *simple_command)
{
	if (!simple_command)
		return ;
	if (simple_command->command_path)
		free(simple_command->command_path);
	if (simple_command->argv)
		string_array_free(simple_command->argv);
	if (simple_command->redir_list)
		list_token_clear(&simple_command->redir_list);
	free(simple_command);
}
