/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:18:42 by mflavio-          #+#    #+#             */
/*   Updated: 2022/09/27 00:18:44 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	i;
	size_t	j;

	dest = 0;
	i = 0;
	if (s1 && set)
	{
		while (ft_strchr(set, s1[i]) && s1[i])
		{
			i++;
		}
		j = ft_strlen(s1);
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
		{
			j--;
		}
		dest = (char *) malloc(sizeof(char) * (j - i + 1));
		if (dest)
			ft_strlcpy(dest, &s1[i], (j - i + 1));
	}
	return (dest);
}
