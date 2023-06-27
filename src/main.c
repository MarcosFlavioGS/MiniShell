/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:01:46 by mflavio-          #+#    #+#             */
/*   Updated: 2023/06/27 20:18:09 by mflavio-         ###   ########.fr       */
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

void	print_argv(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
}

void	free_tables(t_symbols *symbol_table[], t_env *env_table[])
{
	int	i;

	i = 0;
	while (i < 15)
	{
		free(symbol_table[i]);
		i++;
	}
	i = 0;
	while (i < 100)
	{
		free(env_table[i]);
		i++;
	}
}

int	main(int argc, char *argv[], char **envp)
{
	char		*line;
	t_tokenized	*tokens;
	t_symbols	*symbol_table[15];
	t_env		*env_table[100];

	if (argc > 2)
	{
		print_argv(argv);
		return (0);
	}
	init_symbol_table(symbol_table);
	insert_builtins(symbol_table);
	insert_operators(symbol_table);
	insert_env_path(env_table, envp);
	while (1)
	{
		line = get_line();
		lexer(line, &tokens);
		free(line);
		execute(&tokens);
		clear_list(tokens);
		tokens = NULL;
	}
	free_tables(symbol_table, env_table);
	return (0);
}
