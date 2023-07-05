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

void	execute(t_tokenized **tokens)
{
	if (ft_strncmp((*tokens)->token->t_name, "exit", 4) == 0)
		exit (0);
	else if (ft_strncmp((*tokens)->token->t_name, "echo", 4) == 0)
		ft_echo(tokens);
}
