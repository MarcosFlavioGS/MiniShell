/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:13:03 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/25 13:58:15 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/executor/redirect/redirect.h"
#include "../../../include/minishell.h"
#include "../../../include/utils/syscall.h"

int	open_file(t_redirect *redirect, int open_flags)
{
	int	fd_file_in;

	if (!redirect->text)
	{
		ft_printf(2, "minishell: %s: ambiguous redirect\n",
			redirect->text_aux);
		return (-1);
	}
	fd_file_in = syscall_open2(redirect->text, open_flags, 0644, redirect->text);
	return (fd_file_in);
}

int make_redirect_out2(t_io *io, t_redirect *redirect, int flags)
{
	int	fd;

	fd = open_file(redirect, flags);
	if (fd == -1)
		return (1);
	if (io->fd_stdout != 1)
	{
		if (syscall_close(io->fd_stdout, "make_redirect_out2 close fd") == -1)
			return (1);
	}
	io->fd_stdout = fd;
	return (0);
}

int	redirect_dup2(t_io *io)
{
	if (io->fd_stdin != 0)
	{
		if (syscall_dup2(io->fd_stdin, 0, "redirect_dup2 close stdin") == -1)
			return (1);
	}
	if (io->fd_stdout != 1)
	{
		if (syscall_dup2(io->fd_stdout, 1,"redirect_dup2 close stdout") == -1)
			return (1);
	}
	return (0);
}

int	redirect_close_io(t_io *io)
{
	if (io->fd_stdin != 0)
	{
		if (syscall_close(io->fd_stdin, "redirect_close_io close stdin") == -1)
			return (1);
		io->fd_stdin = 0;
	}
	if (io->fd_stdout != 1)
	{
		if (syscall_close(io->fd_stdout, "redirect_close_io close stdout") == -1)
			return (1);
		io->fd_stdout = 1;
	}
	return (0);
}