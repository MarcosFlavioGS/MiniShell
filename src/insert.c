/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:45:12 by mflavio-          #+#    #+#             */
/*   Updated: 2023/06/12 20:45:16 by mflavio-         ###   ########.fr       */
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
