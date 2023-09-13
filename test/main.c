#include "main.h"
#include "../test/assertz/assertz.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

	if (argc == 1 || strcmp(argv[1], "env_manager_test") == 0)
		env_manager_test();
	if (argc == 1 || strcmp(argv[1], "env_manager2_test") == 0)
		env_manager2_test();
	if (argc == 1 || strcmp(argv[1], "lexer_test") == 0)
		lexer_test();
	if (argc == 1 || strcmp(argv[1], "list_token_test") == 0)
		list_token_test();
	if (argc == 1 || strcmp(argv[1], "token_test") == 0)
		token_test();
	if (argc == 1 || strcmp(argv[1], "handler_dquotes_test") == 0)
		handler_dquotes_test();
	if (argc == 1 || strcmp(argv[1], "handler_expand_test") == 0)
		handler_expand_test();
	if (argc == 1 || strcmp(argv[1], "handler_expand2_test") == 0)
		handler_expand2_test();
	if (argc == 1 || strcmp(argv[1], "handler_quotes_test") == 0)
		handler_quotes_test();
	if (argc == 1 || strcmp(argv[1], "handler_separators_test") == 0)
		handler_separators_test();
	if (argc == 1 || strcmp(argv[1], "handler_squotes_test") == 0)
		handler_squotes_test();
	if (argc == 1 || strcmp(argv[1], "handler_word_test") == 0)
		handler_word_test();
	if (argc == 1 || strcmp(argv[1], "syntax_list_test") == 0)
		syntax_list_test();
	if (argc == 1 || strcmp(argv[1], "string_array_test") == 0)
		string_array_test();
	if (argc == 1 || strcmp(argv[1], "simple_command_test") == 0)
		simple_command_test();
	if (argc == 1 || strcmp(argv[1], "executor_utils_test") == 0)
		executor_utils_test();

	return 0;
}
