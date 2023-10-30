/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:23:33 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/29 09:48:47 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/utils/message.h"
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

static int	arg_error(void)
{
	msg_err("minishell: cd: too many arguments");
	return (1);
}

int	ft_cd(t_mini **mini, char **args, int fd)
{
	char	*path;

	(void) fd;
	path = NULL;
	if (args[1] && args[2])
		return (arg_error());
	if (args[1] == NULL)
	{
		path = get_env((*mini)->env, "HOME");
		if (path == NULL)
		{
			msg_err("minishell: cd: HOME not set");
			return (1);
		}
	}
	else
		path = args[1];
	if (chdir(path) != 0)
	{
		ft_putstr_fd(" ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (free(path), 1);
	}
	return (free(path), 0);
}
