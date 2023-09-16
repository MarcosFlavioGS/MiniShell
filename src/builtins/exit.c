/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:48:39 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/12 19:58:06 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exit_shell(t_mini *mini)
{
	mini_destroy(mini);
	exit(0);
}

int	ft_exit(t_mini **mini, char **args, int fd)
{
	int	i;

	i = 0;
	if (args[1])
	{
		if (args[2])
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", fd);
			return (1);
		}
		while (args[1][i])
		{
			if (!ft_isdigit(args[1][i]))
			{
				ft_putstr_fd("minishell: exit: ", fd);
				ft_putstr_fd(args[1], fd);
				ft_putstr_fd(": numeric argument required\n", fd);
				return (1);
			}
			i++;
		}
		exit(ft_atoi(args[1]) % 256);
	}
	mini_destroy(*mini);
	ft_putstr_fd("exit\n", fd);
	exit (0);
}
