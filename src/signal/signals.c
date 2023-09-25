/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:16:18 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/25 14:19:40 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/signal/signals.h"
#include "../../include/minishell.h"
#include "../../include/utils/global_config.h"
#include "../../libft/libft.h"
#include <signal.h>

static void	interrupt_heredoc(int sig)
{
	(void)sig;
	disable_heredoc_config();
	write(2, "\n", 1);
	close(0);
}

static void	print_new_line(int sig)
{
	(void)sig;
	if (get_heredoc_config())
		write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	if (g_global_config & 2)
		rl_redisplay();
}

void	set_signals_heredoc(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &interrupt_heredoc;
	signal(SIGQUIT, SIG_IGN);
	sigaction(SIGINT, &act, NULL);
}

void	set_signals_interative(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &print_new_line;
	signal(SIGQUIT, SIG_IGN);
	sigaction(SIGINT, &act, NULL);
}

void	set_default_signals(void)
{
	set_signals_quit();
	signal(SIGINT, SIG_DFL);
}
