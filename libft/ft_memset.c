/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:16:19 by mflavio-          #+#    #+#             */
/*   Updated: 2022/09/27 00:16:21 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	if (!str)
		return (NULL);
	i = 0;
	p = (unsigned char *) str;
	while (i < n)
	{
		p[i] = (unsigned char) c;
		i++;
	}
	return (str);
}
