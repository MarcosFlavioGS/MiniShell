/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:20:49 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/05 21:24:20 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Remove an environment variable

int	ft_unset(t_mini **mini, char **args, int fd)
{
	int		i;
	char	*tmp;
	char	*tmp2;

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
		tmp = ft_substr(args[i], 0, ft_strchr(args[i], '=') - args[i]);
		tmp2 = ft_substr((*mini)->env[i], 0,
				ft_strchr((*mini)->env[i], '=') - (*mini)->env[i]);
		if (ft_strcmp(tmp, tmp2) == 0)
		{
			free((*mini)->env[i]);
			(*mini)->env[i] = NULL;
		}
		free(tmp);
		free(tmp2);
	}
	return (0);
}