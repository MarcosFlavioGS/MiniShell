/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:50:36 by mflavio-          #+#    #+#             */
/*   Updated: 2023/08/30 23:32:48 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_env_table(t_env **env_table)
{
	int		i;
	t_env	*tmp;
	t_env	*tmp2;

	i = 0;
	while (i < ENV_TABLE_SIZE)
	{
		tmp = env_table[i];
		while (tmp)
		{
			tmp2 = tmp->next;
			free(tmp->name);
			free(tmp->path);
			free(tmp);
			tmp = tmp2;
		}
		i++;
	}
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
