#ifndef TEST_AUX_H
#define TEST_AUX_H

#include "../include/minishell.h"

t_token *test_get_token(char *text, char *aux, t_tok_type type, char *msg_on_error);

#endif