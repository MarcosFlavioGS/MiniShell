/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:52:51 by mflavio-          #+#    #+#             */
/*   Updated: 2023/05/07 01:56:20 by mflavio-         ###   ########.fr       */
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

int	main(void)
{
	char		*line;
	t_tokenized	*tokens;
	t_symbols	*symbol_table[15];

	init_symbol_table(symbol_table);
	insert_builtins(symbol_table);
	while (1)
	{
		line = get_line();
		lexer(line, &tokens);
		free(line);
		execute(&tokens);
		clear_list(tokens);
		tokens = NULL;
	}
	return (0);
}
