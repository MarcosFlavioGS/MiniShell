/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:54:51 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/29 09:56:31 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	validate_key(char *arg)
{
	int	i;

	i = 0;
	if (ft_isdigit(arg[0]) || ft_isalnum(arg[0]) == 0)
		return (1);
	while (arg[i] && arg[i] != '=')
	{
		if (ft_isalnum(arg[i]) == 0 && arg[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

int	ft_export(t_mini **mini, char **args, int fd)
{
	int		i;

	i = 0;
	if (!args[1])
		ft_env(mini, args, fd);
	else
	{
		while (args[++i])
		{
			if (validate_key(args[i]) == 1)
			{
				ft_printf(2, "minishell: export: `%s' not a valid identifier\n",
					args[i]);
				return (1);
			}
			env_add_value(&(*mini)->env, args[i]);
		}
	}
	return (0);
}
