/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:48:39 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/25 11:43:40 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	exit_shell(t_mini *mini, int fd)
{
	int	last_exit_code;

	last_exit_code = mini->last_exit_code;
	mini_destroy(mini);
	ft_putstr_fd("exit\n", fd);
	exit (last_exit_code);
}

int	print_error(char *message, int fd)
{
	ft_putstr_fd(message, fd);
	return (1);
}

int	ft_exit(t_mini **mini, char **args, int fd)
{
	int	i;

	i = 0;
	if (args && args[1])
	{
		if (args[2])
			return (print_error("minishell: exit: too many arguments\n", fd));
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
	exit_shell(*mini, fd);
	return (0);
}
