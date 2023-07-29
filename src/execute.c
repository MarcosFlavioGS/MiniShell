/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:35:55 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/26 18:50:02 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

void	execute(t_mini **mini, t_tokenstream **tokens)
{
	if (!*tokens)
		return ;
	if (ft_strncmp((*tokens)->token->t_name, "exit", 4) == 0)
		exit_shell(mini, tokens);
	else if (ft_strncmp((*tokens)->token->t_name, "echo", 4) == 0)
		ft_echo(tokens);
}
