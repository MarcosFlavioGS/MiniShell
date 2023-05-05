/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:05:19 by mflavio-          #+#    #+#             */
/*   Updated: 2023/01/10 17:27:28 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*gnl_strdup(const char *s)
{
	int		s_size;
	int		i;
	char	*dup;

	i = 0;
	if (!s)
		return (gnl_strdup(""));
	s_size = ft_strlen(s);
	dup = (char *)malloc((s_size + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	read_line(int fd, char **str)
{
	char	*buffer;
	char	*tmp;
	int		r;

	if (!str)
		*str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	tmp = buffer;
	r = read(fd, buffer, BUFFER_SIZE);
	while (r)
	{
		buffer[r] = '\0';
		tmp = gnl_strdup(*str);
		free(*str);
		*str = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(*str, '\n'))
			break ;
		r = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
}

static char	*get_line(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	i++;
	temp = (char *)malloc(sizeof(char) * i + 1);
	if (!temp)
	{
		free(str);
		free(temp);
		return (NULL);
	}
	ft_strlcpy(temp, str, i + 1);
	temp[i] = '\0';
	return (temp);
}

static char	*clean_s(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	i++;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!tmp)
		return (free(str), free(tmp), NULL);
	while (str[i] && str[i] != 0)
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*line;

	line = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) == -1)
		return (NULL);
	read_line(fd, &str[fd]);
	if (!str[fd] || !ft_strlen(str[fd]))
		return (NULL);
	line = get_line(str[fd]);
	str[fd] = clean_s(str[fd]);
	if (!line || !ft_strlen(line))
	{
		free(line);
		free(str[fd]);
		return (NULL);
	}
	return (line);
}
