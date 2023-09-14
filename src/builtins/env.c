/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:59:52 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/05 21:38:42 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_env(t_mini **mini, char **args, int fd)
{
	int	i;

	(void)args;
	i = 0;
	while ((*mini)->env[i])
	{
		ft_putstr_fd((*mini)->env[i], fd);
		ft_putstr_fd("\n", fd);
		i++;
	}
	return (0);
}
