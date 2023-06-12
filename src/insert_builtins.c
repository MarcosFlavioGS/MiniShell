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

void	insert(t_symbols *table[], t_symbols *symbol)
{
	int	index;

	index = symbol->at_value;
	symbol->next = table[index];
	table[index] = symbol;
}

static t_symbols	*insert_echo(void)
{
	t_symbols	*echo;

	echo = malloc(sizeof(t_symbols));
	echo->name = "echo";
	echo->type = "builtin";
	echo->at_value = hash("echo");
	echo->next = NULL;
	return (echo);
}

static t_symbols	*insert_exit(void)
{
	t_symbols	*exit;

	echo = malloc(sizeof(t_symbols));
	exit->name = "exit";
	exit->type = "builtin";
	exit->at_value = hash("exit");
	exit->next = NULL;
	return (exit);
}

void	insert_builtins(t_symbols *symbol_table[])
{
	insert(symbol_table, insert_echo());
	insert(symbol_table, insert_exit());
}
