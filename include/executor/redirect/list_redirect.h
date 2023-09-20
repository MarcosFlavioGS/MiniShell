/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_redirect.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:42:06 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/20 16:42:07 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_REDIRECT_H
# define LIST_REDIRECT_H

# include "../../minishell.h"

void	list_redirect_add_end(t_redirect **list, t_redirect *add);

void	list_redirect_clear(t_redirect **list);

#endif