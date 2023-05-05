/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio <mflavio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:17:12 by mflavio-          #+#    #+#             */
/*   Updated: 2022/12/26 16:41:39 by mflavio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_words(char const *s, char c)
{
	size_t	words;
	size_t	j;

	words = 0;
	j = 0;
	while (*s)
	{
		if (*s != c && !j)
		{
			j = 1;
			words++;
		}
		else if (*s == c)
			j = 0;
		s++;
	}
	return (words);
}

static size_t	special_strlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	k;
	char	**mrx;

	k = 0;
	i = get_words(s, c);
	mrx = (char **) ft_calloc(i + 1, sizeof(char *));
	while (*s)
	{
		if (*s != c)
		{
			mrx[k] = ft_substr(s, 0, special_strlen(s, c));
			s++;
			k++;
		}
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (mrx);
}
