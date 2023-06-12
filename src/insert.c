#include "../mini_shell.h"

void	insert(t_symbols *table[], t_symbols *symbol)
{
	int	index;

	index = symbol->at_value;
	symbol->next = table[index];
	table[index] = symbol;
}
