/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:43:22 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/26 18:02:20 by mflavio-         ###   ########.fr       */
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

void	init_tables(t_mini **mini, char **env)
{
	*mini = malloc(sizeof(t_mini));
	init_env_table((*mini)->env_table);
	init_symbol_table((*mini)->symbol_table);
	insert_env_path((*mini)->env_table, env);
}
