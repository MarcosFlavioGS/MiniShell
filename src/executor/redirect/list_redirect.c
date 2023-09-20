/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:20:21 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/15 22:47:25 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/executor/redirect/list_redirect.h"
#include "../../../include/executor/redirect/redirect.h"
#include "../../../include/minishell.h"

/**
 * list_redirect_add_end - add a redirect to the end of the list
 * @list:	the redirect list
 * @add:	redirect to add
 *
 * If the list is empty, the redirect will (obviously) be the first
 */
void	list_redirect_add_end(t_redirect **list, t_redirect *add)
{
	t_redirect	*last;

	last = *list;
	if (!last)
	{
		*list = add;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = add;
}

/**
 * list_redirect_clear - remove all redirect from the list.
 * @list:	the redirect list
 *
 * After this method the list will point to NULL
 */
void	list_redirect_clear(t_redirect **list)
{
	t_redirect	*current;
	t_redirect	*next;

	current = *list;
	if (!current)
		return ;
	while (current)
	{
		next = current->next;
		redirect_destroy(current);
		current = next;
	}
	*list = current;
}
