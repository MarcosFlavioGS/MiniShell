#ifndef LIST_REDIRECT_DEBUG_H
#define LIST_REDIRECT_DEBUG_H

#include "../../../include/minishell.h"

int	list_redirect_compare(t_redirect *expected, t_redirect *actual);

void list_redirect_printf(t_redirect *list_to_print);

#endif