/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:43:30 by mflavio-          #+#    #+#             */
/*   Updated: 2023/08/31 20:41:24 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_pwd(t_mini **mini, char **args, int fd)
{
	char	cwd[100];

	(void)mini;
	(void)args;
	(void)fd;
	if (getcwd(cwd, 100))
	{
		ft_putendl_fd(cwd, 1);
		return (0);
	}
	else
		return (1);
}
