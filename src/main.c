/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:01:46 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/25 14:02:15 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/utils/global_config.h"

int	g_global_config;

int	main(int argc, char *argv[], char *env[])
{
	t_mini	*mini;

	(void) argv;
	enable_heredoc_config();
	if (argc > 2)
	{
		return (0);
	}
	mini = mini_create(env);
	main_loop(mini);
	return (0);
}
