/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:41:48 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/25 13:57:55 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "../../minishell.h"

int			open_file(t_redirect *redirect, int open_flags);

int 		make_redirect_out2(t_io *io, t_redirect *redirect, int flags);

t_redirect	*redirect_create(t_token *token_redirect, t_token *token_word);

void		redirect_destroy(t_redirect *free);

int			redirect_files(t_command *command);

int			redirect_dup2(t_io *io);

int			redirect_close_io(t_io *io);

#endif