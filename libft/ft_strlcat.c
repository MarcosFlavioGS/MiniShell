/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:17:51 by mflavio-          #+#    #+#             */
/*   Updated: 2022/09/27 00:17:53 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;
	size_t	dest_return;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	i = 0;
	if (dst_size > d_len)
	{
		dest_return = d_len + s_len;
		while (src[i] && d_len < dst_size - 1)
		{
			dest[d_len++] = src[i++];
		}
		dest[d_len] = 0;
		return (dest_return);
	}
	else
	{
		return (s_len + dst_size);
	}
}
