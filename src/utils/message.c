/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:47:25 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 17:57:56 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils/message.h"
#include "../../libft/libft.h"
#include <string.h>
#include <errno.h>

/**
 * msg_fatal_err - print a message in the stderr
 *
 * This method already adds the newline(\n) at the end of the message.
 */
void	msg_fatal_err(const char *msg)
{
	ft_printf(2, "((PANIC)): %s\n", msg);
}

/**
 * msg_syscall_err - print a system call error message in the stderr
 *
 * This method already adds the newline(\n) at the end of the message.
 */
void	msg_syscall_err(const char *msg)
{
	char	*syscall_err_msg;

	syscall_err_msg = strerror(errno);
	ft_printf(2, "minishell: %s: %s\n", msg, syscall_err_msg);
}

/**
 * msg_err - print a message in the stderr
 *
 * This method already adds the newline(\n) at the end of the message.
 */
void	msg_err(const char *msg)
{
	msg_err_nnl(msg);
	ft_printf(2, "\n");
}

/**
 * msg_err_nnl - print a message in the stderr  (nnl = not newline)
 *
 * This method NOT adds the newline(\n) at the end of the message.
 */
void	msg_err_nnl(const char *msg)
{
	ft_printf(2, "%s", msg);
}