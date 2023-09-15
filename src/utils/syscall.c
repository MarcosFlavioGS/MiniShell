/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:07:16 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/15 14:44:48 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils/syscall.h"
#include "../../include/utils/message.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * syscall_open1 - open a file
 * @pathname:	the file name
 * @flags:		open flags
 * @err_msg:	message that will be showed displayed in stdout if any error
 * 				occurs
 *
 * Return:
 * 	On success:
 * 		a new file descriptor (a nonnegative integer) is returned
 * 	On failure:
 * 		-1 is returned
 */
int	syscall_open1(char *pathname, int flags, const char *err_msg)
{
	int	call_return;

	call_return = open(pathname, flags);
	if (call_return == -1)
		msg_syscall_err(err_msg);
	return (call_return);
}

/**
 * syscall_open2 - open a file
 * @pathname:	the file name
 * @flags:		open flags
 * @mode:		the mode flags
 * @err_msg:	message that will be showed displayed in stdout if any error
 * 				occurs
 *
 * Return:
 * 	On success:
 * 		a new file descriptor (a nonnegative integer) is returned
 * 	On failure:
 * 		-1 is returned
 */
int	syscall_open2(char *pathname, int flags, mode_t mode, char *err_msg)
{
	int	call_return;

	call_return = open(pathname, flags, mode);
	if (call_return == -1)
		msg_syscall_err(err_msg);
	return (call_return);
}

/**
 * syscall_close - close a file descriptor
 * @fd:			the file descriptor
 * @err_msg:	message that will be showed displayed in stdout if any error
 * 				occurs
 *
 * Return:
 * 	On success:
 * 		0 is returned
 * 	On failure:
 * 		-1 is returned
 */
int	syscall_close(int fd, const char *err_msg)
{
	int	call_return;

	call_return = close(fd);
	if (call_return == -1)
		msg_syscall_err(err_msg);
	return (call_return);
}

/**
 * syscall_write - write COUNT bytes from BUF in the FD
 * @fd:			the file descriptor to write the buf
 * @buf:		buffer with data to write
 * @count:		number of bytes to be written
 * @err_msg:	message that will be showed displayed in stdout if any error
 * 				occurs
 *
 * Return:
 * 	On success:
 * 		the number of bytes written is returned.
 * 	On failure:
 * 		-1 is returned
 */
ssize_t syscall_write(int fd, const void *buf, size_t count, char *err_msg)
{
	ssize_t	call_return;

	call_return = write(fd, buf, count);
	if (call_return == -1)
		msg_syscall_err(err_msg);
	return (call_return);
}

/**
 * syscall_read - read COUNT bytes from FD to the BUF
 * @fd:			the file descriptor to read
 * @buf:		buffer to store the read data
 * @count:		number of bytes to be read
 * @err_msg:	message that will be showed displayed in stdout if any error
 * 				occurs
 *
 * Return:
 * 	On success:
 * 		the number of bytes readed is returned.
 * 	On failure:
 * 		-1 is returned
 */
ssize_t syscall_read(int fd, void *buf, size_t count, char *err_msg)
{
	ssize_t	call_return;

	call_return = read(fd, buf, count);
	if (call_return == -1)
		msg_syscall_err(err_msg);
	return (call_return);
}