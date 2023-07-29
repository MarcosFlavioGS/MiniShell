/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:47:22 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/05 18:50:55 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

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
