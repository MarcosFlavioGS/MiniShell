/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:03:45 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/22 18:05:15 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_CHILD_H
# define EXECUTE_CHILD_H

# include "../../include/minishell.h"

void	execute_command(t_mini *mini, t_command *simple_command);

#endif