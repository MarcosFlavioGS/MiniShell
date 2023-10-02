/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:23:25 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/29 09:30:32 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../minishell.h"

# define EXEC_CHIL_ERR1 "minishell: %s: command not found\n"
# define EXEC_CHIL_ERR2 "minishell: %s: Is a directory\n"
# define EXEC_CHIL_ERR3 "minishell: %s: Permission denied\n"

void	executor(t_mini *mini);

#endif