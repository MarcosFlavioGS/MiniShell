#include "../../include/executor/executor_utils.h"
#include "../../include/minishell.h"
#include "../../include/executor/simple_command.h"
#include "../../include/parser/list_token.h"
#include "../../include/parser/token.h"
#include "../../debug/executor/simple_command_debug.h"
#include "../assertz/assertz.h"

static void	command_list_create_test()
{
	create_subtitle("command_list_create_test");

	t_token *l01_at00 = token_create("\n",     eol);
	t_token *l01_at01 = token_create("grep",  word); l01_at01->next = l01_at00;
	t_token *l01_at02 = token_create("|",    pipez); l01_at02->next = l01_at01;
	t_token *l01_at03 = token_create("cat",   word); l01_at03->next = l01_at02;
	size_t count = 0;

	t_command *simple_command = command_list_create(l01_at03);
	simple_command_list_printf(simple_command);
	list_token_clear(&l01_at03);
	command_list_destroy(simple_command);

	assert_utils_separator();
}

void executor_utils_test()
{
	create_title("executor_utils_test");

	command_list_create_test();
}