#include "handler_expand2_test.h"
#include "../../../include/parser/handler_expand.h"
#include "../../../include/minishell.h"
#include "../../../include/parser/token.h"
#include "../../../include/parser/list_token.h"
#include "../../../debug/token_list_utils.h"

#include "../../assertz/assertz.h"
#include "../../test_aux.h"

static char *format = "%-55s";

void make_expand_test()
{
	int returnz;
	int equals;

	create_subtitle("make_expand_test");

	char *env[] = {"a=foo", NULL};
	t_mini mini;
	mini.env = env;
	mini.last_exit_code = 42;

	// ==== test 1 ====
	t_token	*l01_at00 = test_get_token("\0",  NULL,    eol, "l01_at00");
	t_token	*l01_at01 = test_get_token("$a",  NULL, expand, "l01_at01"); l01_at01->next = l01_at00;

	t_token	*l01_ex00 = test_get_token("\0",  NULL,  eol,   "l01_ex00");
	t_token	*l01_ex01 = test_get_token("foo", "$a", word,   "l01_ex01"); l01_ex01->next = l01_ex00;

	returnz = make_expand(&l01_at01, &mini);
	equals = list_token_compare(l01_ex01, l01_at01);
	assert_svalue(0, returnz, format, "$a|eol (return)");
	assert_svalue(0, equals, format, "word|eol");
	list_token_clear(&l01_at01); 	list_token_clear(&l01_ex01);
	assert_utils_separator();

	// ==== test 2 ====
	t_token	*l02_at00 = test_get_token("\0", NULL,    eol, "l02_at00");
	t_token	*l02_at01 = test_get_token("$?", NULL, expand, "l02_at01"); l02_at01->next = l02_at00;

	t_token	*l02_ex00 = test_get_token("\0", NULL,    eol, "l02_ex00");
	t_token	*l02_ex01 = test_get_token("42", "$?",   word, "l02_ex01"); l02_ex01->next = l02_ex00;

	returnz = make_expand(&l02_at01, &mini);
	equals = list_token_compare(l02_ex01, l02_at01);
	assert_svalue(0, returnz, format, "$?|eol (return)");
	assert_svalue(0, equals, format, "word|eol");
	list_token_clear(&l02_at01); 	list_token_clear(&l02_ex01);
	assert_utils_separator();

	// ==== test 3 ====
	t_token	*l03_at00 = test_get_token("\0", NULL,    eol, "l03_at00");
	t_token	*l03_at01 = test_get_token("$b", NULL, expand, "l03_at01"); l03_at01->next = l03_at00;

	t_token	*l03_ex00 = test_get_token("\0", NULL,    eol, "l03_ex00");
	t_token	*l03_ex01 = test_get_token(NULL, "$b",   word, "l03_ex01"); l03_ex01->next = l03_ex00;

	returnz = make_expand(&l03_at01, &mini);
	equals = list_token_compare(l03_ex01, l03_at01);
	assert_svalue(0, returnz, format, "$b|eol (return)");
	assert_svalue(0, equals, format, "word(null)|eol");
	list_token_clear(&l03_at01); 	list_token_clear(&l03_ex01);
}

//	handler_separators_test2.c
void handler_expand2_test(int argc, char *argv[])
{
	if (argc != 1 && strcmp(argv[1], "handler_expand2_test") != 0)
		return ;
	create_title("handler_expand2_test");

	make_expand_test();
}
