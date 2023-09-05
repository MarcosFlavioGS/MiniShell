/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:01:46 by mflavio-          #+#    #+#             */
/*   Updated: 2023/08/30 23:35:18 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	char			*line;
	t_tokenstream	*tokens;
	t_mini			*mini;

	(void) argv;
	if (argc > 2)
	{
		return (0);
	}
	line = NULL;
	tokens = NULL;
	mini = mini_create(env);
	main_loop(&mini, line, tokens);
	return (0);
}
