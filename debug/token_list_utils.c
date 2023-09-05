#include "../include/minishell.h"
#include <stdio.h>
#include <string.h>
#include "token_list_utils.h"

static int compare_strings(char *str1, char *str2)
{
	if(str1 && !str2 || !str1 && str2)
		return 1;
	if(!str1 && !str2)
		return 0;
	else
		return strcmp(str1, str2);
}

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
	while(list_to_print)
	{
		printf("text:   %-10s, ", list_to_print->text);
		if(list_to_print->type == separator)
			printf("type: separator\n");
		if(list_to_print->type == redir_in)
			printf("type: redir_in\n");
		if(list_to_print->type == heredoc)
			printf("type: heredoc\n");
		if(list_to_print->type == redir_out)
			printf("type: redit_out\n");
		if(list_to_print->type == append)
			printf("type: append\n");
		if(list_to_print->type == pipez)
			printf("type: pipez\n");
		if(list_to_print->type == expand)
			printf("type: expand\n");
		if(list_to_print->type == dquote)
			printf("type: dquote\n");
		if(list_to_print->type == squote)
			printf("type: squote\n");
		if(list_to_print->type == eol)
			printf("type: eol\n");
		if(list_to_print->type == word)
			printf("type: word\n");
		list_to_print = list_to_print->next;
	}
}
