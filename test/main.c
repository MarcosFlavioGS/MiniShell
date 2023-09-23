#include "main.h"

int	g_continue_heredoc;

int main(int argc, char *argv[])
{
	env_manager_test(argc, argv);
	env_manager2_test(argc, argv);

	// executor folder
	executor_utils_test(argc, argv);
	path_creator_test(argc, argv);
	simple_command_test(argc, argv);
	string_array_test(argc, argv);
	heredoc_test(argc, argv);

	// parser folder
	handler_dquotes_test(argc, argv);
	handler_expand_test(argc, argv);
	handler_expand2_test(argc, argv);
	handler_quotes_test(argc, argv);
	handler_separators_test(argc, argv);
	handler_squotes_test(argc, argv);
	handler_word_test(argc, argv);
	lexer_test(argc, argv);
	list_token_test(argc, argv);
	parser_test(argc, argv);
	syntax_list_test(argc, argv);
	token_test(argc, argv);

	return 0;
}
