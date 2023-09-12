/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:35:55 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/12 20:14:27 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	execute(t_mini **mini, char *cmd, int fd)
{
	builtin_func_t	func_ptr;
	char			**args;

	args = malloc(sizeof(char *) * 2);
	args[0] = ft_strdup(cmd);
	args[1] = NULL;
	func_ptr = get_builtin(cmd);
	if (func_ptr != NULL)
		func_ptr(mini, args, fd);
	else
		printf("Command '%s' not recognized\n", cmd);
}
