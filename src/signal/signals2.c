/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:16:18 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/25 10:29:38 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/signal/signals.h"
#include "../../include/minishell.h"
#include "../../include/utils/global_config.h"
#include "../../libft/libft.h"
#include <signal.h>

static void print_quit(int sig)
{
	(void)sig;
	ft_printf(2, "Quit\n");
}

void	set_signals_quit(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &print_quit;
	sigaction(SIGQUIT, &act, NULL);
}