/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:59:06 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/15 14:44:04 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSCALL_H
# define SYSCALL_H

# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>

int		syscall_open1(char *pathname, int flags, const char *err_msg);

int		syscall_open2(char *pathname, int flags, mode_t mode, char *err_msg);

int		syscall_close(int fd, const char *err_msg);

ssize_t	syscall_write(int fd, const void *buf, size_t count, char *err_msg);

ssize_t	syscall_read(int fd, void *buf, size_t count, char *err_msg);

#endif