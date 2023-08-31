/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:56:36 by mflavio-          #+#    #+#             */
/*   Updated: 2023/08/30 23:34:53 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static unsigned int	char_sum(const char *str)
{
	unsigned int	n;
	int				i;

	n = 0;
	i = 0;
	while (str[i])
	{
		n += str[i++];
	}
	return (n);
}

unsigned int	hash(const char *str, int size)
{
	return ((char_sum(str) * ft_strlen(str)) % size);
}
