/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:35:55 by mflavio-          #+#    #+#             */
/*   Updated: 2023/06/20 18:36:07 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static void	ft_echo(t_tokenized **tokens)
{
	t_tokenized	*tmp;

	if ((*tokens)->next == NULL)
		return ;
	else
	{
		tmp = (*tokens)->next;
		while (tmp)
		{
			printf("%s", tmp->token->t_name);
			tmp = tmp->next;
		}
		printf("\n");
	}
}

void	execute(t_tokenized **tokens)
{
	if (ft_strncmp((*tokens)->token->t_name, "exit", 4) == 0)
		exit (0);
	else if (ft_strncmp((*tokens)->token->t_name, "echo", 4) == 0)
		ft_echo(tokens);
}
