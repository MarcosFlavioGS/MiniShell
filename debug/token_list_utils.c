#include "../include/minishell.h"
#include "debug_utils.h"
#include <stdio.h>
#include "token_list_utils.h"

int	list_token_compare_type(t_token *expected, t_token *actual)
{
	while(expected && actual)
	{
		if(expected->type != actual->type)
			return 1;
		expected = expected->next;
		actual   = actual->next;
	}
	if((expected && !actual) || (!expected && actual))
		return 1;
	return 0;
}

int	list_token_compare(t_token *expected, t_token *actual)
{
	while(expected && actual)
	{
		if(compare_strings(expected->text, actual->text))
			return 1;
		if(compare_strings(expected->text_aux, actual->text_aux))
			return 1;
		if(expected->type != actual->type)
			return 1;
		expected = expected->next;
		actual   = actual->next;
	}
	if((expected && !actual) || (!expected && actual))
		return 1;
	return 0;
}



void list_token_printf(t_token *list_to_print)
{
	printf("[");
	while(list_to_print)
	{
		printf("[");
		printf("text:%s, ",    list_to_print->text);
		printf("text_aux:%s, ", list_to_print->text_aux);
		if(list_to_print->type == separator)
			printf("type: separator");
		if(list_to_print->type == redir_in)
			printf("type: redir_in");
		if(list_to_print->type == heredoc)
			printf("type: heredoc");
		if(list_to_print->type == redir_out)
			printf("type: redit_out");
		if(list_to_print->type == append)
			printf("type: append");
		if(list_to_print->type == pipez)
			printf("type: pipez");
		if(list_to_print->type == expand)
			printf("type: expand");
		if(list_to_print->type == dquote)
			printf("type: dquote");
		if(list_to_print->type == squote)
			printf("type: squote");
		if(list_to_print->type == eol)
			printf("type: eol");
		if(list_to_print->type == word)
			printf("type: word");
		list_to_print = list_to_print->next;
		if(list_to_print)
			printf("], ");
		else
			printf("]");
	}
	printf("]");
}
