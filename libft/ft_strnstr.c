/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:18:27 by mflavio-          #+#    #+#             */
/*   Updated: 2022/09/27 00:18:28 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_size;

	i = 0;
	little_size = ft_strlen(little);
	if (!little_size)
		return ((char *) big);
	if (!len)
		return (NULL);
	while (big[i] && i + little_size <= len)
	{
		if (!ft_strncmp(&big[i], little, little_size))
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
