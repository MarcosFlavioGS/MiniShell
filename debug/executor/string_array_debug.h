#ifndef STRING_ARRAY_DEBUG_H
#define STRING_ARRAY_DEBUG_H

#include "../../include/minishell.h"

int string_array_compare(char **expected, char **actual);

void string_array_printf(char **array);

#endif