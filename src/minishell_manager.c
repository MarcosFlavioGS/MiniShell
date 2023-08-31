/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:56:54 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/08/30 23:35:23 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/libft.h"
#include "../include/utils/message.h"

t_mini	*mini_create(char **env)
{
	t_mini	*new_mini;

	new_mini = ft_calloc(1, sizeof(*new_mini));
	if (!new_mini)
	{
		msg_fatal_err(ERR_MSG_1);
		exit(1);
	}
	new_mini->env = env_dup(env);
	if (!new_mini->env)
	{
		mini_destroy(new_mini);
		msg_fatal_err(ERR_MSG_2);
		exit(1);
	}
	return (new_mini);
}

void	mini_destroy(t_mini *mini)
{
	if (!mini)
		return ;
	if (mini->env)
		env_free(mini->env);
	free(mini);
}
