/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:08:24 by mflavio-          #+#    #+#             */
/*   Updated: 2022/09/27 00:22:50 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	size_bytes;

	if (!size || !nmemb)
		return (malloc(0));
	if (size > 2147483647 / nmemb)
		return (NULL);
	size_bytes = nmemb * size;
	p = malloc(size_bytes);
	if (p == NULL)
		return (p);
	ft_bzero(p, size_bytes);
	return (p);
}
