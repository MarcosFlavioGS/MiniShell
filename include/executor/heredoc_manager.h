/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:25:48 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/20 14:11:29 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_MANAGER_H
# define HEREDOC_MANAGER_H

# include "../minishell.h"

int		make_all_heredocs(t_mini *mini);

void	close_all_heredocs(t_command *command_list);

#endif