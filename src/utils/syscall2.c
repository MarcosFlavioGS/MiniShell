/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:07:16 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/25 14:03:02 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils/syscall.h"
#include "../../include/utils/message.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * syscall_dup - duplicate a file descriptor
 * @fd:			fd to dup
 * @err_msg:	message that will be showed displayed in stdout if any error
 * 				occurs
 *
 * Return:
 * 	On success:
 * 		a new file descriptor (a nonnegative integer) is returned
 * 	On failure:
 * 		-1 is returned
 */
int	syscall_dup(int fd, const char *err_msg)
{
	int	call_return;

	call_return = dup(fd);
	if (call_return == -1)
		msg_syscall_err(err_msg);
	return (call_return);
}

/**
 * syscall_dup2 - the file descriptor @new is adjusted so that it refers to the
 * 				  same open file description as @old.
 * @old:		old fd
 * @new:		new fd
 * @err_msg:	message that will be showed displayed in stdout if any error
 * 				occurs
 *
 * Return:
 * 	On success:
 * 		a new file descriptor (a nonnegative integer) is returned
 * 	On failure:
 * 		-1 is returned
 */
int	syscall_dup2(int old, int new, const char *err_msg)
{
	int	call_return;

	call_return = dup2(old, new);
	if (call_return == -1)
		msg_syscall_err(err_msg);
	return (call_return);
}

/**
 *
 *
 * Return:
 * 	On success:
 * 		0 is returned
 * 	On failure:
 * 		-1 is returned
 */
int	syscall_pipe(int pipe_arr[2], const char *err_msg)
{
	int	call_return;

	call_return = pipe(pipe_arr);
	if (call_return == -1)
		msg_syscall_err(err_msg);
	return (call_return);
}

/**
 *
 * Return:
 * 	On success:
 * 		0 is returned to child process
 * 		the child's pid is returned to parent
 * 	On failure:
 * 		-1 is returned
 */
pid_t	syscall_fork(const char *err_msg)
{
	pid_t	call_return;

	call_return = fork();
	if (call_return == -1)
		msg_syscall_err(err_msg);
	return (call_return);
}
