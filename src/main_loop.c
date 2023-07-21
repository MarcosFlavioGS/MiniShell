/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:14:05 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/20 20:49:40 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static void	clear_list(t_tokenized *tokens)
{
	t_tokenized	*tmp;

	while (tokens)
	{
		tmp = tokens->next;
		free(tokens->token->t_name);
		free(tokens->token);
		free(tokens);
		tokens = tmp;
	}
}

void	main_loop(t_mini *mini, char *line, t_tokenized *tokens)
{
	while (1)
	{
		line = get_line();
		if (!line)
			continue ;
		lexer(line, &tokens);
		free(line);
		parser(mini, &tokens);
		execute(&tokens);
		clear_list(tokens);
		tokens = NULL;
	}
}
