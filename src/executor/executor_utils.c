/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:38:16 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/13 18:24:38 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor/executor_utils.h"
#include "../../include/executor/simple_command.h"
#include "../../include/minishell.h"
#include "../../include/parser/list_token.h"
#include <stdlib.h>

/**
 * command_list_add_end - add a command to the end of the list
 * @list:	the command list
 * @add:	command to add
 *
 * If the list is empty, the command will (obviously) be the first
 */
static void	command_list_add_end(t_command **command_list, t_command *add)
{
	t_command	*last;

	last = *command_list;
	if (!last)
	{
		*command_list = add;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = add;
}

/**
 *
 * Return:
 * 	On success:
 * 		A command list is return
 * 	On failure:
 * 		NULL is returned
*/
t_command	*command_list_create(t_token *token_list)
{
	t_command	*command_list;
	t_command	*command;
	size_t		count;
	t_token		*actual_token;

	command_list = NULL;
	count = 0;
	actual_token = list_token_get(token_list, 0);
	while (actual_token->type != eol)
	{
		command = command_create(token_list, &count);
		if (!command)
		{
			command_list_destroy(command_list);
			return (NULL);
		}
		command_list_add_end(&command_list, command);
		actual_token = list_token_get(token_list, count);
	}
	return (command_list);
}

void	command_list_destroy(t_command *command_list)
{
	t_command	*command_tmp;

	command_tmp = command_list;
	if (!command_list)
		return ;
	while (command_list)
	{
		command_tmp = command_list->next;
		command_destroy(command_list);
		command_list = command_tmp;
	}
}
