/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:13:03 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/23 00:06:46 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/executor/redirect/redirect.h"
#include "../../../include/minishell.h"
#include "../../../include/utils/syscall.h"
#include "../../../include/utils/message.h"

static int	open_file(t_redirect *redirect, int open_flags)
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

static int make_redirect_out2(t_io *io, t_redirect *redirect, int flags)
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







int make_redirect_out(t_io *io, t_redirect *redirect)
{
	fprintf(stderr, "make_redirect_out: called\n");
	return (make_redirect_out2(io, redirect, O_CREAT | O_TRUNC | O_WRONLY));
}

int make_redirect_append(t_io *io, t_redirect *redirect)
{
	return (make_redirect_out2(io, redirect, O_CREAT | O_APPEND | O_WRONLY));
}

static int make_redirect_in(t_io *io, t_redirect *redirect)
{
	int	fd;

	fd = open_file(redirect, O_RDONLY);
	if (fd == -1)
		return (1);
	if (io->fd_stdin != 0)
	{
		if (syscall_close(io->fd_stdin, "make_redirect_in close stdin fd") == -1)
			return (1);
	}
	io->fd_stdin = fd;
	return (0);
}

static int	make_redirect_heredoc(t_io *io, t_redirect *redir_heredoc)
{
	if (io->fd_stdin != 0)
	{
		syscall_close(io->fd_stdin,
			"make_redirect_heredoc close io.stdin");
		return (1);
	}
	io->fd_stdin = redir_heredoc->hdoc_fd;
	redir_heredoc->hdoc_fd = -1;
	return (0);
}

int redirect_files(t_command *command)
{
	int			status;
	t_redirect	*redirect;

	status = 0;
	redirect = command->redir_list;
	while (redirect)
	{
		if(redirect->type == heredoc)
			status = make_redirect_heredoc(&command->io, redirect);
		if(redirect->type == redir_in)
			status = make_redirect_in(&command->io, redirect);
		if(redirect->type == redir_out)
			status = make_redirect_out(&command->io, redirect);
		if(redirect->type == append)
			status = make_redirect_append(&command->io, redirect);
		if (status)
			break ;
		redirect = redirect->next;
	}
	return (status);
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