/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:17:45 by mflavio-          #+#    #+#             */
/*   Updated: 2022/09/27 00:17:46 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = malloc(((s1_len + s2_len) * sizeof(char)) + 1);
	if (dest)
	{
		ft_strlcpy(dest, s1, s1_len + 1);
		ft_strlcat(dest, s2, s1_len + s2_len + 1);
		return (dest);
	}
	return (NULL);
}
