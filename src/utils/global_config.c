/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 00:02:35 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/25 09:32:19 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils/global_config.h"
#include "../../include/minishell.h"

void	enable_heredoc_config()
{
	g_global_config = g_global_config | 1;
}

void	disable_heredoc_config()
{
	g_global_config = g_global_config & ~1;
}

int		get_heredoc_config()
{
	return (g_global_config & 1);
}

void	enable_redisplay()
{
	g_global_config = g_global_config | 2;
}

void	disable_redisplay()
{
	g_global_config = g_global_config & ~2;
}

int		get_redisplay_config()
{
	return (g_global_config & 2);
}