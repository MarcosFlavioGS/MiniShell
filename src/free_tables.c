/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:50:36 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/26 18:58:51 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

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
