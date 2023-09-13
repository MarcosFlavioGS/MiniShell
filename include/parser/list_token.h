/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_token.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:59:58 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 10:59:58 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_TOKEN_H
# define LIST_TOKEN_H

# include "../minishell.h"

void	list_token_add_end(t_token **list, t_token *add);

int		list_token_add_index(t_token **list, t_token *add, size_t index);

t_token	*list_token_get(t_token *list, size_t index);

void	list_token_clear(t_token **list);

int		list_token_remove(t_token **list, size_t index);

#endif
