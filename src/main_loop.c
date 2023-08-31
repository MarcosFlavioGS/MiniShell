/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:14:05 by mflavio-          #+#    #+#             */
/*   Updated: 2023/08/30 23:35:13 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	clear_list(t_tokenstream *tokens)
{
	t_tokenstream	*tmp;

	while (tokens)
	{
		tmp = tokens->next;
		free(tokens->token->t_name);
		free(tokens->token);
		free(tokens);
		tokens = tmp;
	}
}

static void	print(t_tokenstream **tokens)
{
	t_tokenstream	*tmp;

	tmp = *tokens;
	while (tmp)
	{
		printf(
			"Token name: %s\nToken type: %i\nSymbol id: %d\nQuote: %i\n",
			tmp->token->t_name, tmp->token->type,
			tmp->token->at_value, tmp->token->quote);
		tmp = tmp->next;
	}
}

void	main_loop(t_mini **mini, char *line, t_tokenstream *tokens)
{
	while (1)
	{
		line = get_line();
		if (!line)
		{
			exit_shell(mini, &tokens);
		}
		lexer(line, &tokens);
		free(line);
		print(&tokens);
		execute(mini, &tokens);
		clear_list(tokens);
		tokens = NULL;
	}
}
