/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:01:46 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/05 18:46:30 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static void	print_argv(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
}

static void	free_tables(t_symbols *symbol_table[], t_env *env_table[])
{
	int	i;

	i = 0;
	while (i < SYMBOL_TABLE_SIZE)
	{
		free(symbol_table[i]);
		i++;
	}
	i = 0;
	while (i < ENV_TABLE_SIZE)
	{
		free(env_table[i]);
		i++;
	}
}



int	main(int argc, char *argv[], char **envp)
{
	char		*line;
	t_tokenized	*tokens;
	t_mini		*mini;

	if (argc > 2)
	{
		print_argv(argv);
		return (0);
	}
	line = NULL;
	tokens = NULL;
	mini = NULL;
	init_tables(mini, envp);
	main_loop(line, tokens);
	free_tables(mini->symbol_table, mini->env_table);
	return (0);
}
