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

#include "../../include/minishell.h"

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
		env_remove_value(&(*mini)->env, args[i]);
	}
	return (0);
}
