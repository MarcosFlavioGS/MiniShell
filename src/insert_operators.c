/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_operators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:57:26 by mflavio-          #+#    #+#             */
/*   Updated: 2023/06/27 19:05:35 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static t_symbols	*insert_in(char *operator)
{
	t_symbols	*operator_node;

	operator_node = malloc(sizeof(t_symbols));
	operator_node->name = operator;
	operator_node->type = "operator";
	operator_node->at_value = hash(operator);
	operator_node->next = NULL;
	return (operator_node);
}

void	insert_operators(t_symbols *symbol_table[])
{
	insert(symbol_table, insert_in("<"));
	insert(symbol_table, insert_in("<<"));
	insert(symbol_table, insert_in(">"));
	insert(symbol_table, insert_in(">>"));
	insert(symbol_table, insert_in("|"));
}
