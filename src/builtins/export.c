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

#include "../../include/minishell.h"

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
			env_add_value(&(*mini)->env, args[i]);
		}
	}
	return (0);
}
