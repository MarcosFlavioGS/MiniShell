/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:29:29 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 16:34:24 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils/die.h"
#include "../../include/minishell.h"
#include "../../include/utils/message.h"
#include <stdlib.h>

/**
 * die - closes the program in any error.
 * @mini:	program struct to free
 * @msg:	NULL or a message to show in the stderr
*/
void	die(t_mini *mini, char *msg)
{
	if (msg)
		msg_fatal_err(msg);
	mini_destroy(mini);
	exit(1);
}
