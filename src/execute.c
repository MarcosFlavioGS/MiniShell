/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:35:55 by mflavio-          #+#    #+#             */
/*   Updated: 2023/08/30 23:32:35 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	execute(t_mini **mini, t_tokenstream **tokens)
{
	if (!*tokens)
		return ;
	if (ft_strncmp((*tokens)->token->t_name, "exit", 4) == 0)
		exit_shell(mini, tokens);
	else if (ft_strncmp((*tokens)->token->t_name, "echo", 4) == 0)
		ft_echo(tokens);
}
