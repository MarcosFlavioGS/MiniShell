/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_builtins2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:43:11 by mflavio-          #+#    #+#             */
/*   Updated: 2023/06/12 20:43:20 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

t_symbols	*insert_unset(void)
{
	t_symbols	*unset;

	unset = malloc(sizeof(t_symbols));
	unset->name = "unset";
	unset->type = "builtin";
	unset->at_value = hash("unset");
	unset->next = NULL;
	return (unset);
}

t_symbols	*insert_env(void)
{
	t_symbols	*env;

	env = malloc(sizeof(t_symbols));
	env->name = "env";
	env->type = "builtin";
	env->at_value = hash("env");
	env->next = NULL;
	return (env);
}

t_symbols	*insert_export(void)
{
	t_symbols	*export;

	export = malloc(sizeof(t_symbols));
	export->name = "export";
	export->type = "builtin";
	export->at_value = hash("export");
	export->next = NULL;
	return (export);
}
