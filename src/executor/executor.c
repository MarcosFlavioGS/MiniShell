/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:25:54 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/20 16:37:39 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor/executor.h"
#include "../../include/executor/heredoc_manager.h"

void	executor(t_mini *mini)
{
	int	heredoc_status;

	mini->last_exit_code = 0;
	heredoc_status = make_all_heredocs(mini);
	if (heredoc_status)
		return ;
	printf("executer\n");
}
