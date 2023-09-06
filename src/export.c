/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:54:51 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/05 21:46:10 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Add a new environment variable
static void	ft_addenv(char *str, char **env)
{
	int		i;
	char	**new_env;

	i = 0;
	while (env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (env[++i])
		new_env[i] = ft_strdup(env[i]);
	new_env[i] = ft_strdup(str);
	new_env[i + 1] = NULL;
	free_array(env);
	env = new_env;
}

// Set a new value to an environment variable
static void	ft_setenv(char *str, char **env)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = -1;
	while (env[++i])
	{
		tmp = ft_substr(str, 0, ft_strchr(str, '=') - str);
		tmp2 = ft_substr(env[i], 0, ft_strchr(env[i], '=') - env[i]);
		if (ft_strncmp(tmp, tmp2, ft_strlen(tmp)) == 0)
		{
			free(env[i]);
			env[i] = ft_strdup(str);
			free(tmp);
			free(tmp2);
			return;
		}
		free(tmp);
		free(tmp2);
	}
}

// Get the value of an environment variable
static char	*ft_getenv(char *str, char **env)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = -1;
	while (env[++i])
	{
		tmp = ft_substr(str, 0, ft_strchr(str, '=') - str);
		tmp2 = ft_substr(env[i], 0, ft_strchr(env[i], '=') - env[i]);
		if (ft_strncmp(tmp, tmp2, ft_strlen(tmp)) == 0)
		{
			free(tmp);
			free(tmp2);
			return (ft_strchr(env[i], '=') + 1);
		}
		free(tmp);
		free(tmp2);
	}
	return (NULL);
}

static void	ft_print_export(t_mini **mini, int fd)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	while ((*mini)->env[++i])
	{
		j = -1;
		ft_putstr_fd("declare -x ", fd);
		tmp = ft_substr((*mini)->env[i], 0,
                        ft_strchr((*mini)->env[i], '=') - (*mini)->env[i]);
		ft_putstr_fd(tmp, fd);
		free(tmp);
		if (ft_strchr((*mini)->env[i], '='))
		{
			ft_putstr_fd("=\"", fd);
			tmp = ft_strchr((*mini)->env[i], '=') + 1;
			while (tmp[++j])
			{
				if (tmp[j] == '\"' || tmp[j] == '$' || tmp[j] == '\\')
					ft_putchar_fd('\\', fd);
				ft_putchar_fd(tmp[j], fd);
			}
			ft_putstr_fd("\"", fd);
		}
		ft_putstr_fd("\n", fd);
	}
}

int	ft_export(t_mini **mini, char **args, int fd)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!args[1])
		ft_print_export(mini, fd);
	else
	{
		while (args[++i])
		{
			if (ft_strchr(args[i], '='))
			{
				tmp = ft_substr(args[i], 0,
								ft_strchr(args[i], '=') - args[i]);
				if (ft_getenv(tmp, (*mini)->env))
					ft_setenv(args[i], (*mini)->env);
				else
					ft_addenv(args[i], (*mini)->env);
				free(tmp);
			}
		}
	}
	return (0);
}
