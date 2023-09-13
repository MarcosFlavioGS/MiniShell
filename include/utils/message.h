/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:48:04 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/13 18:19:51 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H

# define ERR_MSG_1 "malloc error! minishell struct"
# define ERR_MSG_2 "malloc error! env_dup"

void	msg_fatal_err(const char *msg);

void	msg_syscall_err(const char *msg);

void	msg_err(const char *msg);

void	msg_err_nnl(const char *msg);

#endif