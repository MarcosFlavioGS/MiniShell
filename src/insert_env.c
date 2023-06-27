/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:40:34 by mflavio-          #+#    #+#             */
/*   Updated: 2023/06/27 19:38:15 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static char	*get_string_before_equal(char *str)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i] != '=')
		i++;
	new = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] != '=')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static void	insert_envs(t_env *env_table[], t_env *node)
{
	int	index;

	index = hash(node->name);
	node->next = env_table[index];
	env_table[index] = node;
}

void	insert_env_path(t_env *env_table[], char **envp)
{
	t_env	*node;
	int		i;

	i = 0;
	while (i < 100)
	{
		env_table[i] = NULL;
		i++;
	}
	i = 0;
	while (envp[i])
	{
		node = (t_env *)malloc(sizeof(t_env));
		node->name = ft_strdup(get_string_before_equal(envp[i]));
		node->path = ft_strdup(envp[i] + ft_strlen(node->name) + 1);
		node->next = NULL;
		insert_envs(env_table, node);
		i++;
	}
}
