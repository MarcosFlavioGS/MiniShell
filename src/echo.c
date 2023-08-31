/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:47:22 by mflavio-          #+#    #+#             */
/*   Updated: 2023/08/30 23:32:16 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_echo(t_tokenstream **tokens)
{
	t_tokenstream	*tmp;

	if ((*tokens)->next == NULL)
		return (0);
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
	return (0);
}
