/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:45:22 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/22 19:49:27 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_H
# define PIPELINE_H
# include "../minishell.h"

#define IN 0
#define OUT 1

typedef	struct s_pipeline
{
	int			tmp_fd_in;
	int			pipe[2];
	t_command	*simple_command;
	size_t		count_child;
	int			is_sucessfull;
}	t_pipeline;

void	execute_pipeline(t_mini *mini);

#endif