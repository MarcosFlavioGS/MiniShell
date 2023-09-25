/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:19:43 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/25 14:33:04 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor/pipeline.h"
#include "../../include/minishell.h"
#include "../../include/utils/syscall.h"

void	pipeline_die(t_pipeline	*pipeline)
{
	if (pipeline->tmp_fd_in > 0)
		syscall_close(pipeline->tmp_fd_in, "pipeline_die: close tmp_fd_in");
	syscall_close(pipeline->pipe[IN], "pipeline_die: close pipeline->pipe[IN]");
	syscall_close(pipeline->pipe[OUT],
		"pipeline_die: close pipeline->pipe[OUT]");
}
