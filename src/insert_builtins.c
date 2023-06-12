/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:26:57 by mflavio-          #+#    #+#             */
/*   Updated: 2023/06/12 19:27:02 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static t_symbols	*insert_echo(void)
{
	t_symbols	*echo;

	echo = malloc(sizeof(t_symbols));
	echo->name = "echo";
	echo->type = "builtin";
	echo->at_value = hash("echo");
	echo->next = NULL;
	return (echo);
}

static t_symbols	*insert_cd(void)
{
	t_symbols	*cd;

	cd = malloc(sizeof(t_symbols));
	cd->name = "cd";
	cd->type = "builtin";
	cd->at_value = hash("cd");
	cd->next = NULL;
	return (cd);
}

static t_symbols	*insert_pwd(void)
{
	t_symbols	*pwd;

	pwd = malloc(sizeof(t_symbols));
	pwd->name = "pwd";
	pwd->type = "builtin";
	pwd->at_value = hash("pwd");
	pwd->next = NULL;
	return (pwd);
}

static t_symbols	*insert_exit(void)
{
	t_symbols	*exit;

	exit = malloc(sizeof(t_symbols));
	exit->name = "exit";
	exit->type = "builtin";
	exit->at_value = hash("exit");
	exit->next = NULL;
	return (exit);
}

void	insert_builtins(t_symbols *symbol_table[])
{
	insert(symbol_table, insert_echo());
	insert(symbol_table, insert_exit());
	insert(symbol_table, insert_cd());
	insert(symbol_table, insert_pwd());
	insert(symbol_table, insert_export());
	insert(symbol_table, insert_unset());
	insert(symbol_table, insert_env());
}
