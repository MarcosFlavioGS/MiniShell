/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:25:48 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/29 10:21:28 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_MANAGER_H
# define HEREDOC_MANAGER_H

# include "../minishell.h"

# define HDOC_MANAGER_ERR1 "heredoc_manager[HDOC_MANAGER_ERR1]"

int		make_all_heredocs(t_mini *mini);

void	close_all_heredocs(t_command *command_list);

#endif