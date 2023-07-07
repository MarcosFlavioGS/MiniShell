/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:43:22 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/05 19:41:17 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static void	init_symbol_table(t_symbols *symbol_table[])
{
	int	i;

	i = 0;
	while (i < SYMBOL_TABLE_SIZE)
	{
		symbol_table[i++] = NULL;
	}
}

static void	init_env_table(t_env *env_table[])
{
	int		i;

	i = 0;
	while (i < ENV_TABLE_SIZE)
	{
		env_table[i] = NULL;
		i++;
	}
}

void	init_tables(t_mini *mini, char **env)
{
	mini = malloc(sizeof(t_mini));
	mini->symbol_table = malloc(sizeof(t_symbols *) * SYMBOL_TABLE_SIZE);
	mini->env_table = malloc(sizeof(t_env *) * ENV_TABLE_SIZE);
	init_symbol_table(mini->symbol_table);
	init_env_table(mini->env_table);
	insert_builtins(mini->symbol_table);
	insert_operators(mini->symbol_table);
	insert_env_path(mini->env_table, env);
}
