/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:59:52 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/05 21:07:21 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_env(t_mini **mini, char ***env, int fd)
{
	int	i;

	(void)mini;
	i = 0;
	while ((*env)[i])
	{
		ft_putendl_fd((*env)[i], fd);
		i++;
	}
	return (0);
}