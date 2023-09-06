/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:07:45 by mflavio-          #+#    #+#             */
/*   Updated: 2023/08/31 19:32:00 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

typedef void (*builtin_func_t)(t_mini **mini, char **args, int fd);

void set_builtins(builtin_func_t builtins[7]) {
	builtins[0] = (void *)&ft_echo;
	builtins[1] = (void *)&ft_cd;
	builtins[2] = (void *)&ft_pwd;
	builtins[3] = (void *)&ft_export;
	builtins[4] = (void *)&ft_unset;
	builtins[5] = (void *)&ft_env;
	builtins[6] = (void *)&ft_exit;
}

builtin_func_t get_builtin(char *cmd) {
	builtin_func_t builtins[7];

	set_builtins(builtins);
	if (ft_strncmp(cmd, "echo", 5) == 0)
		return builtins[0];
	else if (ft_strncmp(cmd, "cd", 3) == 0)
		return builtins[1];
	else if (ft_strncmp(cmd, "pwd", 4) == 0)
		return builtins[2];
	else if (ft_strncmp(cmd, "export", 7) == 0)
		return builtins[3];
	else if (ft_strncmp(cmd, "unset", 6) == 0)
		return builtins[4];
	else if (ft_strncmp(cmd, "env", 4) == 0)
		return builtins[5];
	else if (ft_strncmp(cmd, "exit", 5) == 0)
		return builtins[6];
	else
		return NULL;
}
