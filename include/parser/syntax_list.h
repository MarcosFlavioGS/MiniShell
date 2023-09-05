/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:00:06 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 16:52:31 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_LIST_H
# define SYNTAX_LIST_H

# include "../minishell.h"

void	syntax_list(t_mini *mini, char *str_line);

void	syntax_list_clear_mini(t_mini *mini);
#endif