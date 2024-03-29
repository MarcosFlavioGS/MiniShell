/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:07:45 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/25 15:37:39 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	set_builtins(t_builtin_func builtins[7])
{
	builtins[0] = (void *)&ft_echo;
	builtins[1] = (void *)&ft_cd;
	builtins[2] = (void *)&ft_pwd;
	builtins[3] = (void *)&ft_export;
	builtins[4] = (void *)&ft_unset;
	builtins[5] = (void *)&ft_env;
	builtins[6] = (void *)&ft_exit;
}

/*
** t_builtin_func get_builtin(char *cmd);
**
** The function receives a string representing a builtin function and returns
** a pointer to that function:
**
** t_builyin_func func;
**
** func = get_builtin(echo);
**
** Now call the pointer as a normal function with parameters:
**
** func(mini, "Hello", 1);
*/
t_builtin_func	get_builtin(char *cmd)
{
	t_builtin_func	builtins[7];

	if (cmd == NULL)
		return (NULL);
	set_builtins(builtins);
	if (ft_strncmp(cmd, "echo", 5) == 0)
		return (builtins[0]);
	else if (ft_strncmp(cmd, "cd", 3) == 0)
		return (builtins[1]);
	else if (ft_strncmp(cmd, "pwd", 4) == 0)
		return (builtins[2]);
	else if (ft_strncmp(cmd, "export", 7) == 0)
		return (builtins[3]);
	else if (ft_strncmp(cmd, "unset", 6) == 0)
		return (builtins[4]);
	else if (ft_strncmp(cmd, "env", 4) == 0)
		return (builtins[5]);
	else if (ft_strncmp(cmd, "exit", 5) == 0)
		return (builtins[6]);
	else
		return (NULL);
}
