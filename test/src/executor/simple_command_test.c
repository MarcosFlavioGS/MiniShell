#include "simple_command_test.h"
#include "../../../debug/executor/simple_command_debug.h"
#include "../../../include/executor/simple_command.h"
#include "../../../include/minishell.h"
#include "../../../include/parser/list_token.h"
#include "../../../include/parser/token.h"
#include "../../assertz/assertz.h"

static void command_create_test()
{
	t_token *l01_at00 = token_create("\n", eol);
	t_token *l01_at01 = token_create("cat", word); l01_at01->next = l01_at00;
	size_t count = 0;

	t_command *simple_command = command_create(l01_at01, &count);
	simple_command_printf(simple_command);
	command_destroy(simple_command);
	list_token_clear(&l01_at01);

	assert_utils_separator();

	// ==== test 2 ====
	t_token *l02_at00 = token_create("\n", eol);
	t_token *l02_at01 = token_create("-e", word);   l02_at01->next = l02_at00;
	t_token *l02_at02 = token_create("grep", word); l02_at02->next = l02_at01;
	size_t count2 = 0;

	t_command *simple_command2 = command_create(l02_at02, &count2);
	simple_command_printf(simple_command2);
	command_destroy(simple_command2);
		list_token_clear(&l02_at02);

	assert_utils_separator();

	// ==== test 3 ====
	t_token *l03_at00 = token_create("\n",    eol);
	t_token *l03_at01 = token_create("-x",   word); l03_at01->next = l03_at00;
	t_token *l03_at02 = token_create("-e",   word); l03_at02->next = l03_at01;
	t_token *l03_at03 = token_create("grep", word); l03_at03->next = l03_at02;
	size_t count3 = 0;

	t_command *simple_command3 = command_create(l03_at03, &count3);
	simple_command_printf(simple_command3);
	command_destroy(simple_command3);
		list_token_clear(&l03_at03);

	assert_utils_separator();

	// ==== test 4 ====
	t_token *l04_at00 = token_create("\n",        eol);
	t_token *l04_at01 = token_create("file",     word); l04_at01->next = l04_at00;
	t_token *l04_at02 = token_create("<",    redir_in); l04_at02->next = l04_at01;
	t_token *l04_at03 = token_create("-x",       word); l04_at03->next = l04_at02;
	t_token *l04_at04 = token_create("-e",       word); l04_at04->next = l04_at03;
	t_token *l04_at05 = token_create("grep",     word); l04_at05->next = l04_at04;
	size_t count4 = 0;

	t_command *simple_command4 = command_create(l04_at05, &count4);
	simple_command_printf(simple_command4);
	command_destroy(simple_command4);
		list_token_clear(&l04_at05);

	assert_utils_separator();

	// ==== test 5 ====
	t_token *l05_at00 = token_create("\n",        eol);
	t_token *l05_at01 = token_create("EOF",      word); l05_at01->next = l05_at00;
	t_token *l05_at02 = token_create("<<",    heredoc); l05_at02->next = l05_at01;
	t_token *l05_at03 = token_create("file",     word); l05_at03->next = l05_at02;
	t_token *l05_at04 = token_create("<",    redir_in); l05_at04->next = l05_at03;
	t_token *l05_at05 = token_create("-x",       word); l05_at05->next = l05_at04;
	t_token *l05_at06 = token_create("-e",       word); l05_at06->next = l05_at05;
	t_token *l05_at07 = token_create("grep",     word); l05_at07->next = l05_at06;
	size_t count5 = 0;

	t_command *simple_command5 = command_create(l05_at07, &count5);
	simple_command_printf(simple_command5);
	command_destroy(simple_command5);
		list_token_clear(&l05_at07);

	assert_utils_separator();

	// ==== test 6 ====
	t_token *l06_at00 = token_create("\n",        eol);
	t_token *l06_at01 = token_create("EOF",      word); l06_at01->next = l06_at00;
	t_token *l06_at02 = token_create("<<",    heredoc); l06_at02->next = l06_at01;
	t_token *l06_at03 = token_create("-x",       word); l06_at03->next = l06_at02;
	t_token *l06_at04 = token_create("-e",       word); l06_at04->next = l06_at03;
	t_token *l06_at05 = token_create("file",     word); l06_at05->next = l06_at04;
	t_token *l06_at06 = token_create("<",    redir_in); l06_at06->next = l06_at05;
	t_token *l06_at07 = token_create("grep",     word); l06_at07->next = l06_at06;
	size_t count6 = 0;

	t_command *simple_command6 = command_create(l06_at07, &count6);
	simple_command_printf(simple_command6);
	command_destroy(simple_command6);
		list_token_clear(&l06_at07);
}


void simple_command_test(int argc, char *argv[])
{
	if (argc != 1 &&  strcmp(argv[1], "simple_command_test") != 0)
		return ;
	create_title("simple_command_test");

	command_create_test();
}