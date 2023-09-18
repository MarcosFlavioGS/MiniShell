#include "simple_command_debug.h"
#include "../debug_utils.h"
#include "string_array_debug.h"
#include "redirect/list_redirect_debug.h"

/**
 * simple_command_compare -
 *
 * Return:
 * 	0 equals
 * 	1 not equals
 */
int	simple_command_compare(t_command *expected, t_command *actual)
{
	while (expected && actual)
	{
		if (compare_strings(expected->command_path, actual->command_path))
			return 1;
		if (string_array_compare(expected->argv, actual->argv))
			return 1;
		if (expected->pid != actual->pid)
			return 1;
		if (expected->io.stdin != actual->io.stdin)
			return 1;
		if (expected->io.stdout != actual->io.stdout)
			return 1;
		if (list_redirect_compare(expected->redir_list, actual->redir_list))
			return 1;
		expected = expected->next;
		actual   = actual->next;
	}
	if((expected && !actual) || (!expected && actual))
		return 1;
	return 0;
}

void	simple_command_printf(t_command *print)
{
	printf("pid: %d, ", print->pid);
	printf("command: %s, ", print->command_path);
	printf("argv: ");
	string_array_printf(print->argv);
	printf(", io: [stdio:%d, stdout:%d], ", print->io.stdin, print->io.stdout);
	printf("redirects: ");
	list_redirect_printf(print->redir_list);
}

void	simple_command_list_printf(t_command *print)
{
	printf("[");
	while(print)
	{
		printf("[");
		simple_command_printf(print);
		print = print->next;
		if (print)
			printf("], ");
		else
			printf("]");
	}
	printf("]");
}

void	simple_command_list_printf_nl(t_command *print)
{
	while(print)
	{
		simple_command_printf(print);
		print = print->next;
		printf("\n");
	}
}