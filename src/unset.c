/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:20:49 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/13 19:21:17 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Check if the environment variable exists
int	check_env(t_mini *mini, char *arg)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = mini->env;
	while (tmp[i])
	{
		if (!ft_strncmp(tmp[i], arg, ft_strlen(arg) + 1))
			return (1);
	}
	return (0);
}

int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

// Remove an element from an array
char	**remove_elem(char **array, char *arg)
{
	char	**new_array;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_array = malloc(sizeof(char *) * (ft_array_len(array)));
	while (array[i])
	{
		if (!ft_strncmp(array[i], arg, ft_strlen(arg) + 1))
		{
			new_array[j] = ft_strdup(array[i]);
			j++;
		}
		i++;
	}
	new_array[j] = NULL;
	return (new_array);
}

// Remove the environment variable
void	remove_env(t_mini **mini, char *arg)
{
	char **new_array;

	new_array = remove_elem((*mini)->env, arg);
	free_array((*mini)->env);
	(*mini)->env = new_array;
}

// Remove an environment variable
int	ft_unset(t_mini **mini, char **args, int fd)
{
	int		i;

	i = -1;
	while (args[++i])
	{
		if (ft_strchr(args[i], '='))
		{
			ft_putstr_fd("unset: `", fd);
			ft_putstr_fd(args[i], fd);
			ft_putendl_fd("': not a valid identifier", fd);
			return (1);
		}
		if (check_env(*mini, args[i]))
			remove_env(mini, args[i]);
	}
	return (0);
}
