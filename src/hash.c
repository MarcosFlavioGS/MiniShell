/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:56:36 by mflavio-          #+#    #+#             */
/*   Updated: 2023/05/10 16:56:38 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

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

unsigned int	hash(const char *str)
{
	return ((char_sum(str) * ft_strlen(str)) % 15);
}
