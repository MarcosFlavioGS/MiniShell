/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:47:22 by mflavio-          #+#    #+#             */
/*   Updated: 2023/08/31 20:40:47 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_echo(t_mini **mini, char **args, int fd)
{
	int	i;
	int	n;

	(void)mini;
	i = 1;
	n = 0;
	if (args[1] && ft_strncmp(args[1], "-n", 3) == 0)
	{
		n = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], fd);
		if (args[i + 1])
			ft_putstr_fd(" ", fd);
		i++;
	}
	if (!n)
		ft_putstr_fd("\n", fd);
	return (0);
}