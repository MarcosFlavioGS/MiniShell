/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:01:46 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/20 17:07:26 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	g_continue_heredoc;

int	main(int argc, char *argv[], char *env[])
{
	t_mini	*mini;

	(void) argv;
	g_continue_heredoc = 1;
	if (argc > 2)
	{
		return (0);
	}
	mini = mini_create(env);
	main_loop(mini);
	return (0);
}
