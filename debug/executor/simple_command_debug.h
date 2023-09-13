#ifndef SIMPLE_COMMAND_DEBUG_H
#define SIMPLE_COMMAND_DEBUG_H

#include "../../include/minishell.h"

int	simple_command_compare(t_command *command1, t_command *command2);

void	simple_command_printf(t_command *print);

void	simple_command_list_printf(t_command *print);

void	simple_command_list_printf_nl(t_command *print);

#endif