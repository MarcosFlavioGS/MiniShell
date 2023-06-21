/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:01:46 by mflavio-          #+#    #+#             */
/*   Updated: 2023/06/21 18:01:52 by mflavio-         ###   ########.fr       */
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

void	init_symbol_table(t_symbols *symbol_table[])
{
	int	i;

	i = 0;
	while (i < 15)
	{
		symbol_table[i++] = NULL;
	}
}

int	main(int argc, char *argv[], char **env)
{
	char		*line;
	t_tokenized	*tokens;
	t_symbols	*symbol_table[15];

	if (argc > 2)
		return (0);
	init_symbol_table(symbol_table);
	insert_builtins(symbol_table);
	while (1)
	{
		if (argc == 2)
			line = read_file(argv[1]);
		else
			line = get_line();
		lexer(line, &tokens);
		free(line);
		execute(&tokens);
		clear_list(tokens);
		tokens = NULL;
	}
	return (0);
}
