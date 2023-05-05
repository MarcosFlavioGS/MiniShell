/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:16:10 by mflavio-          #+#    #+#             */
/*   Updated: 2022/09/27 00:16:12 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_p;
	const char	*src_p;

	dest_p = (char *) dest;
	src_p = (const char *) src;
	if ((src_p == NULL) || (dest_p == NULL))
	{
		return (NULL);
	}
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			dest_p[n] = src_p[n];
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
