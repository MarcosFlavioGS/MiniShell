#ifndef TOKEN_LIST_UTILS_H
#define TOKEN_LIST_UTILS_H

#include "../include/minishell.h"

int	list_token_compare_type(t_token *expected, t_token *actual);

int	list_token_compare(t_token *expected, t_token *actual);

void list_token_printf(t_token *list_to_print);

#endif
