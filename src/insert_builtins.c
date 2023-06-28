/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:26:57 by mflavio-          #+#    #+#             */
/*   Updated: 2023/06/12 19:27:02 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static t_symbols	*insert_in(char *builtin)
{
	t_symbols	*builtin_node;

	builtin_node = malloc(sizeof(t_symbols));
	builtin_node->name = ft_strdup(builtin);
	builtin_node->type = "builtin";
	builtin_node->at_value = hash(builtin_node->name);
	builtin_node->next = NULL;
	return (builtin_node);
}

void	insert_builtins(t_symbols *symbol_table[])
{
	insert(symbol_table, insert_in("echo"));
	insert(symbol_table, insert_in("exit"));
	insert(symbol_table, insert_in("pwd"));
	insert(symbol_table, insert_in("cd"));
	insert(symbol_table, insert_in("unset"));
	insert(symbol_table, insert_in("env"));
	insert(symbol_table, insert_in("export"));
}
