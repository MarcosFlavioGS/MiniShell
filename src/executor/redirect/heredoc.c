/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:24:31 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/29 10:01:23 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/executor/redirect/heredoc.h"
#include "../../../include/minishell.h"
#include "../../../include/utils/message.h"
#include "../../../include/utils/syscall.h"
#include "../../../include/utils/global_config.h"
#include "../../../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <readline/readline.h>

/**
 * create_tmp_file - create the temporary heredoc file
 * @file_name:	the temporary file name
 *
 * Return:
 *	On successful:
 *		return a fd (a nonnegative integer) to tmp heredoc file filled
 *	On failure:
 *		-1 is returned
 */
static int	create_tmp_file(char *file_name)
{
	int		heredoc_fd_writ;
	int		open_flags;

	open_flags = O_WRONLY | O_CREAT | O_EXCL | O_TRUNC ;
	heredoc_fd_writ = open(file_name, open_flags, 0600);
	if (heredoc_fd_writ < 0)
	{
		msg_syscall_err(ERR_HDOC_04);
		return (-1);
	}
	return (heredoc_fd_writ);
}

/**
 * check_line - check if the line is valid to be added to the heredoc temporary
 * file
 * @line:		the line entered by the user
 * @limiter:	the heredoc limiter
 *
 * Return:
 * 	On success (line is valid):
 * 		0 is returned
 * 	On failure (line is invalid):
 * 		1 is returned
 */
static int	check_line(char *line, char *limiter)
{
	if (!line)
	{
		if (get_heredoc_config())
		{
			msg_err_nnl("minishell: warning: ");
			msg_err_nnl("here-document delimited by end-of-file (wanted `");
			msg_err_nnl(limiter);
			msg_err("')");
		}
		return (1);
	}
	else if (ft_strncmp(line, limiter, ft_strlen(line)) == 0
		&& ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		return (1);
	return (0);
}

/**
 * write_file - fills the temporary heredoc file until reaching the 'limiter'
 * or EOF
*/
void	write_file(int hedoc, char *limiter)
{
	char	*line;
	int		continue_while;

	continue_while = 1;
	while (continue_while && get_heredoc_config())
	{
		line = readline("> ");
		if (!check_line(line, limiter))
		{
			if (syscall_write(hedoc, line, ft_strlen(line), ERR_HDOC_02) == -1)
				continue_while = 0;
			if (syscall_write(hedoc, "\n", 1, ERR_HDOC_03) == -1)
				continue_while = 0;
		}
		else
			continue_while = 0;
		if (line)
			free(line);
		if (!continue_while)
			break ;
	}
}

/**
 * make_heredoc - create a temp file and fill it with stdin input
 * @limiter:	the heredoc limiter to stop read from stdin
 *
 * Return:
 *	On successful:
 *		return a fd (a nonnegative integer) to tmp heredoc file filled
 *	On failure:
 *		-1 is returned
 */
int	make_heredoc(char *limiter)
{
	int		heredoc_fd_read;
	int		heredoc_fd_writ;

	heredoc_fd_read = -1;
	heredoc_fd_writ = create_tmp_file(TEMP_FILE);
	if (heredoc_fd_writ == -1)
		return (heredoc_fd_read);
	heredoc_fd_read = syscall_open1(TEMP_FILE, O_RDONLY, ERR_HDOC_06);
	unlink(TEMP_FILE);
	if (heredoc_fd_read != -1)
		write_file(heredoc_fd_writ, limiter);
	syscall_close(heredoc_fd_writ, ERR_HDOC_07);
	return (heredoc_fd_read);
}
