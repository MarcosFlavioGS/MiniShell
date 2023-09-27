/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:48:39 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/26 21:35:27 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/utils/message.h"

static void	exit_shell(t_mini *mini)
{
	int	last_exit_code;

	last_exit_code = mini->last_exit_code;
	mini_destroy(mini);
	exit (last_exit_code);
}

static void	invalid_arg(t_mini **mini, char *arg)
{
	ft_printf(2, "minishell: exit: %s: numeric argument required\n", arg);
	(*mini)->last_exit_code = 2;
	exit_shell(*mini);
}

int	ft_exit(t_mini **mini, char **args, int fd)
{
	int	i;

	i = 0;
	ft_putstr_fd("exit\n", fd);
	if (args && args[1])
	{
		if (args[2])
		{
			msg_err(" too many arguments");
			(*mini)->last_exit_code = 1;
		}
		else
		{
			while (args[1][i])
			{
				if ((args[1][i] == '+' || args[1][i] == '-') && i == 0)
					i++;
				if (!ft_isdigit(args[1][i]))
					invalid_arg(mini, args[1]);
				i++;
			}
			(*mini)->last_exit_code = (ft_atoi(args[1]) % 256);
		}
	}
	exit_shell(*mini);
	return (0);
}
