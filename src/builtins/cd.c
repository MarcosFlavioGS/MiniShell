/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:23:33 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/26 20:24:52 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <errno.h>

static char	*get_env(char **env, char *key)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] == key[j] && env[i][j] != '=')
			j++;
		if (env[i][j] == '=' && key[j] == '\0')
		{
			value = ft_strdup(env[i] + j + 1);
			return (value);
		}
		i++;
	}
	return (NULL);
}

static int	arg_error(int fd)
{
	ft_putstr_fd("minishell: cd: too many arguments\n", fd);
	return (1);
}

int	ft_cd(t_mini **mini, char **args, int fd)
{
	char	*path;

	if (args[1] && args[2])
		return (arg_error(fd));
	if (args[1] == NULL)
	{
		path = get_env((*mini)->env, "HOME");
		if (path == NULL)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", fd);
			return (1);
		}
	}
	else
		path = args[1];
	if (chdir(path) != 0)
	{
		ft_putstr_fd("minishell: cd: ", fd);
		ft_putstr_fd(path, fd);
		ft_putstr_fd(": ", fd);
		ft_putstr_fd(strerror(errno), fd);
		ft_putstr_fd("\n", fd);
		return (1);
	}
	return (0);
}
