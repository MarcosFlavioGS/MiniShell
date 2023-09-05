/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:40 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 16:39:07 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser/list_token.h"
#include "../../include/parser/token.h"
#include "../../include/minishell.h"
#include <stdlib.h>

/**
 * list_token_add_end -	add a token to the end of the list
 * @list:	the token list
 * @add:	token to add
 *
 * If the list is empty, the token will (obviously) be the first
 */
void	list_token_add_end(t_token **list, t_token *add)
{
	t_token	*last;

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
 * list_token_add_index -	add a token to the list and pushes the other tokens
 *							forward in the list.
 * @list:	the token list
 * @add:	token to add
 * @index:	index to add the token
 *
 * E.g:	list before: A->C	| list before: Y->Z		| list before: foo
 *		add B to index 1	| add X to index 0		| add bar to index 0
 *		list after: A->B->C	| list after: X->Y->Z	| list after: bar->foo
 *
 * Return:
 *	On success:
 *		0
 *	On failure:
 *		1 if index is invalid(value that does not exist) or if list is empty
 */
int	list_token_add_index(t_token **list, t_token *add, size_t index)
{
	t_token	*current;

	current = list_token_get(*list, index);
	if (!current)
		return (1);
	if (index == 0)
	{
		add->next = *list;
		*list = add;
		return (0);
	}
	else
	{
		current = list_token_get(*list, index - 1);
		add->next = current->next;
		current->next = add;
		return (0);
	}
	return (1);
}

/**
 * list_token_get - return the token at the given index
 * @list:	the token list
 * @index:	the index
 *
 * If the index is invalid this method return NULL
 *
 * Return:
 *	On success:
 *		a token
 *	On failure:
 *		NULL
 */
t_token	*list_token_get(t_token *list, size_t index)
{
	t_token	*returnz;
	size_t	count;

	returnz = list;
	count = 0;
	while (returnz != NULL && count < index)
	{
		returnz = returnz->next;
		count++;
	}
	return (returnz);
}

/**
 * list_token_clear - remove all tokens from the list.
 * @list:	the token list
 *
 * After this method the list will point to NULL
 */
void	list_token_clear(t_token **list)
{
	t_token	*current;
	t_token	*next;

	current = *list;
	if (!current)
		return ;
	while (current)
	{
		next = current->next;
		token_destroy(current);
		current = next;
	}
	*list = current;
}

/**
 * list_token_remove - remove a token from the list, that token is also free.
 * @list:	the token list
 * @list:	token index that will be removed
 *
 * When a token is removed its next token takes its place in the list.
 * As a list ends with a NULL, if the removed token is the last one, its place
 * is occupied by a NULL.
 * If the list only has one token and that token is removed (index 0), the list
 * will obviously point to NULL.
 *
 * E.g:	list before: A->B->C	| list before: Y->Z		| list before: foo->bar
 *		remove B index 1		| remove Y index 0		| remove bar index 1
 *		list after: A->C		| list after: Z			| list after: foo
 *
 * Return:
 *	On success:
 *		0
 *	On failure:
 *		1 if index is invalid(value that does not exist) or if list is empty
 */
int	list_token_remove(t_token **list, size_t index)
{
	t_token	*current;
	t_token	*remove;

	current = *list;
	if (!current)
		return (1);
	if (index == 0)
	{
		*list = current->next;
		token_destroy(current);
		return (0);
	}
	index--;
	while (current != NULL && index--)
		current = current->next;
	if (!current)
		return (1);
	remove = current->next;
	if (!remove)
		return (1);
	current->next = remove->next;
	token_destroy(remove);
	return (0);
}
