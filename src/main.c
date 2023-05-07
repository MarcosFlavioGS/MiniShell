/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:52:51 by mflavio-          #+#    #+#             */
/*   Updated: 2023/05/06 13:28:06 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int	main(void)
{
	char *line;

	while (1)
	{
		line = readline("$> ");
		if (ft_strncmp(line, "exit", 4) == 0)
			break;
		if (ft_strnstr(line, "echo", 4))
		{
			printf("%s\n", line);
		}
	}
	return (0);
}
