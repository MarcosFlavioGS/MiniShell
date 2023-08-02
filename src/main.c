/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:01:46 by mflavio-          #+#    #+#             */
/*   Updated: 2023/08/02 16:37:09 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int	main(int argc, char *argv[], char **envp)
{
	char			*line;
	t_tokenstream	*tokens;
	t_mini			*mini;

	(void)argv;
	if (argc > 2)
	{
		return (0);
	}
	line = NULL;
	tokens = NULL;
	mini = NULL;
	init_tables(&mini, envp);
	main_loop(&mini, line, tokens);
	free_env_table(mini->env_table);
	return (0);
}
