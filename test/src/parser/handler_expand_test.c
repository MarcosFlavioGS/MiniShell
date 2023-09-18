#include "handler_expand_test.h"
#include "../../../debug/token_list_utils.h"
#include "../../../include/minishell.h"
#include "../../../include/parser/handler_expand.h"
#include "../../../include/parser/token.h"
#include "../../../include/parser/list_token.h"
#include "../../test_aux.h"
#include "../../assertz/assertz.h"

static char *format = "%-55s";

static void remove_invalid_expand_test()
{
	int is_equal;

	create_subtitle("remove_invalid_expand_test");

	// ==== test 1 ====
	t_token	*l01_at00 = test_get_token("\0", NULL, eol, 	"l01_at00");
	t_token	*l01_at01 = test_get_token("\"", NULL, dquote, 	"l01_at01"); l01_at01->next = l01_at00;
	t_token	*l01_at02 = test_get_token("$", NULL,  expand, 	"l01_at02"); l01_at02->next = l01_at01;
	t_token	*l01_at03 = test_get_token("\"", NULL, dquote,	"l01_at03"); l01_at03->next = l01_at02;
	t_token	*l01_at04 = test_get_token("$", NULL,  expand, 	"l01_at04"); l01_at04->next = l01_at03;

	t_token	*l01_ex00 = test_get_token("\0", NULL, eol,		"l01_ex00");
	t_token	*l01_ex01 = test_get_token("\"", NULL, dquote,	"l01_ex01"); l01_ex01->next = l01_ex00;
	t_token	*l01_ex02 = test_get_token("$", NULL,  expand,	"l01_ex02"); l01_ex02->next = l01_ex01;
	t_token	*l01_ex03 = test_get_token("\"", NULL, dquote,	"l01_ex03"); l01_ex03->next = l01_ex02;

	remove_invalid_expand(&l01_at04);
	is_equal = list_token_compare_type(l01_ex03, l01_at04);
	assert_svalue(0, is_equal, format, "dquote|expand|dquote|eol");
	list_token_clear(&l01_at04); 	list_token_clear(&l01_ex03);


	// ==== test 2 ====
	t_token	*l02_at01 = test_get_token("\0", NULL, eol,    "l02_at01");
	t_token	*l02_at02 = test_get_token("$", NULL,  expand, "l02_at02"); l02_at02->next = l02_at01;
	t_token	*l02_at03 = test_get_token("\'", NULL, squote, "l02_at03"); l02_at03->next = l02_at02;
	t_token	*l02_at04 = test_get_token("$", NULL,  expand, "l02_at04"); l02_at04->next = l02_at03;
	t_token	*l02_at05 = test_get_token("\'", NULL, squote, "l02_at05"); l02_at05->next = l02_at04;
	t_token	*l02_at06 = test_get_token("$", NULL,  expand, "l02_at06"); l02_at06->next = l02_at05;
	t_token	*l02_at07 = test_get_token("\"", NULL, dquote, "l02_at07"); l02_at07->next = l02_at06;
	t_token	*l02_at08 = test_get_token("$", NULL,  expand, "l02_at08"); l02_at08->next = l02_at07;
	t_token	*l02_at09 = test_get_token("\"", NULL, dquote, "l02_at09"); l02_at09->next = l02_at08;
	t_token	*l02_at10 = test_get_token("$", NULL,  expand, "l02_at10"); l02_at10->next = l02_at09;

	t_token	*l02_ex01 = test_get_token("\0", NULL, eol,    "l02_ex01");
	t_token	*l02_ex02 = test_get_token("$", NULL,  expand, "l02_ex02"); l02_ex02->next = l02_ex01;
	t_token	*l02_ex03 = test_get_token("\'", NULL, squote, "l02_ex03"); l02_ex03->next = l02_ex02;
	t_token	*l02_ex04 = test_get_token("$", NULL,  expand, "l02_ex04"); l02_ex04->next = l02_ex03;
	t_token	*l02_ex05 = test_get_token("\'", NULL, squote, "l02_ex05"); l02_ex05->next = l02_ex04;
	t_token	*l02_ex06 = test_get_token("\"", NULL, dquote, "l02_ex06"); l02_ex06->next = l02_ex05;
	t_token	*l02_ex07 = test_get_token("$", NULL,  expand, "l02_ex07"); l02_ex07->next = l02_ex06;
	t_token	*l02_ex08 = test_get_token("\"", NULL, dquote, "l02_ex08"); l02_ex08->next = l02_ex07;

	remove_invalid_expand(&l02_at10);
	is_equal = list_token_compare_type(l02_ex08, l02_at10);
	assert_svalue(0, is_equal, format, "dquote|expand|dquote|squote|expand|squote|expand|eol");
	list_token_clear(&l02_at10);  	list_token_clear(&l02_ex08);

	// ==== test 3 ====
	t_token	*l03_at00 = test_get_token("\0", NULL, eol,    "l03_at00");
	t_token	*l03_at01 = test_get_token("\"", NULL, dquote, "l03_at01"); l03_at01->next = l03_at00;
	t_token	*l03_at02 = test_get_token("$", NULL,  expand, "l03_at02"); l03_at02->next = l03_at01;
	t_token	*l03_at03 = test_get_token("\"", NULL, dquote, "l03_at03"); l03_at03->next = l03_at02;
	t_token	*l03_at04 = test_get_token("$", NULL,  expand, "l03_at04"); l03_at04->next = l03_at03;
	t_token	*l03_at05 = test_get_token("$", NULL,  expand, "l03_at05"); l03_at05->next = l03_at04;

	t_token	*l03_ex00 = test_get_token("\0", NULL, eol,    "l03_ex00");
	t_token	*l03_ex01 = test_get_token("\"", NULL, dquote, "l03_ex01"); l03_ex01->next = l03_ex00;
	t_token	*l03_ex02 = test_get_token("$", NULL,  expand, "l03_ex02"); l03_ex02->next = l03_ex01;
	t_token	*l03_ex03 = test_get_token("\"", NULL, dquote, "l03_ex03"); l03_ex03->next = l03_ex02;
	t_token	*l03_ex04 = test_get_token("$", NULL,  expand, "l03_ex04"); l03_ex04->next = l03_ex03;
	t_token	*l03_ex05 = test_get_token("$", NULL,  expand, "l03_ex05"); l03_ex05->next = l03_ex04;

	remove_invalid_expand(&l03_at05);
	is_equal = list_token_compare_type(l03_ex05, l03_at05);
	assert_svalue(0, is_equal, format, "expand|expand|dquote|expand|dquote|eol");
	list_token_clear(&l03_at05); 	list_token_clear(&l03_ex05);

}

static void	make_invalid_expand_word_test()
{
	int is_equal;

	create_subtitle("make_invalid_expand_word_test");

	// ==== test 1 ====
	t_token	*l01_at01 = test_get_token("\0", NULL, eol,    "l01_at01");
	t_token	*l01_at02 = test_get_token("$",  NULL, expand, "l01_at02"); l01_at02->next = l01_at01;

	t_token	*l01_ex01 = test_get_token("\0", NULL, eol,    "l01_ex01");
	t_token	*l01_ex02 = test_get_token("$",  NULL, word,   "l01_ex02"); l01_ex02->next = l01_ex01;

	make_invalid_expand_word(&l01_at02);
	is_equal = list_token_compare_type(l01_ex02, l01_at02);
	assert_svalue(0, is_equal, format, "word|eol");
	list_token_clear(&l01_at02); list_token_clear(&l01_ex02);

	// ==== test 2 ====
	t_token	*l02_at01 = test_get_token("\0", NULL, eol,    "l02_at01");
	t_token	*l02_at02 = test_get_token("=a", NULL, word,   "l02_at02"); l02_at02->next = l02_at01;
	t_token	*l02_at03 = test_get_token("$",  NULL, expand, "l02_at03"); l02_at03->next = l02_at02;

	t_token	*l02_ex01 = test_get_token("\0", NULL, eol,    "l02_ex01");
	t_token	*l02_ex02 = test_get_token("=a", NULL, word,   "l02_ex02"); l02_ex02->next = l02_ex01;
	t_token	*l02_ex03 = test_get_token("$",  NULL, word,   "l02_ex03"); l02_ex03->next = l02_ex02;

	make_invalid_expand_word(&l02_at03);
	is_equal = list_token_compare_type(l02_ex03, l02_at03);
	assert_svalue(0, is_equal, format, "word|word|eol");
	list_token_clear(&l02_at03); list_token_clear(&l02_ex03);
}

static void make_expand_after_heredoc_word_test()
{
	int is_equal;

	create_subtitle("make_expand_after_heredoc_word_test");

	// ==== test 1 ====
	t_token	*l01_at01 = test_get_token("\0", NULL, eol,     "l01_at01");
	t_token	*l01_at02 = test_get_token("$",  NULL, expand,  "l01_at02"); l01_at02->next = l01_at01;
	t_token	*l01_at03 = test_get_token("<<", NULL, heredoc, "l01_at03"); l01_at03->next = l01_at02;

	t_token	*l01_ex01 = test_get_token("\0", NULL, eol,     "l01_ex01");
	t_token	*l01_ex02 = test_get_token("$",  NULL, word,    "l01_ex02"); l01_ex02->next = l01_ex01;
	t_token	*l01_ex03 = test_get_token("<<", NULL, heredoc, "l01_ex03"); l01_ex03->next = l01_ex02;

	make_expand_after_heredoc_word(&l01_at03);
	is_equal = list_token_compare_type(l01_ex03, l01_at03);
	assert_svalue(0, is_equal, format, "heredoc|word|eol");
	list_token_clear(&l01_at03); list_token_clear(&l01_ex03);

	// ==== test 2 ====
	t_token	*l02_at01 = test_get_token("\0",   NULL, eol,     "l02_at01");
	t_token	*l02_at02 = test_get_token("\"",   NULL, dquote,  "l02_at02"); l02_at02->next = l02_at01;
	t_token	*l02_at03 = test_get_token("path", NULL, word,    "l02_at03"); l02_at03->next = l02_at02;
	t_token	*l02_at04 = test_get_token("$",    NULL, expand,  "l02_at04"); l02_at04->next = l02_at03;
	t_token	*l02_at05 = test_get_token("\"",   NULL, dquote,  "l02_at05"); l02_at05->next = l02_at04;
	t_token	*l02_at06 = test_get_token("a",    NULL, word,    "l02_at06"); l02_at06->next = l02_at05;
	t_token	*l02_at07 = test_get_token("$",    NULL, expand,  "l02_at07"); l02_at07->next = l02_at06;
	t_token	*l02_at08 = test_get_token("<<",   NULL, heredoc, "l02_at08"); l02_at08->next = l02_at07;

	t_token	*l02_ex01 = test_get_token("\0",   NULL, eol,     "l02_ex01");
	t_token	*l02_ex02 = test_get_token("\"",   NULL, dquote,  "l02_ex02"); l02_ex02->next = l02_ex01;
	t_token	*l02_ex03 = test_get_token("path", NULL, word,    "l02_ex03"); l02_ex03->next = l02_ex02;
	t_token	*l02_ex04 = test_get_token("$",    NULL, word,    "l02_ex04"); l02_ex04->next = l02_ex03;
	t_token	*l02_ex05 = test_get_token("\"",   NULL, dquote,  "l02_ex05"); l02_ex05->next = l02_ex04;
	t_token	*l02_ex06 = test_get_token("a",    NULL, word,    "l02_ex06"); l02_ex06->next = l02_ex05;
	t_token	*l02_ex07 = test_get_token("$",    NULL, word,    "l02_ex07"); l02_ex07->next = l02_ex06;
	t_token	*l02_ex08 = test_get_token("<<",   NULL, heredoc, "l02_ex08"); l02_ex08->next = l02_ex07;

	make_expand_after_heredoc_word(&l02_at08);
	is_equal = list_token_compare_type(l02_at08, l02_ex08);
	assert_svalue(0, is_equal, format, "heredoc|word|word|dquote|word|word|dquote|eol");
	list_token_clear(&l02_at08); list_token_clear(&l02_ex08);

}

//	handler_expand_test.c
void handler_expand_test(int argc, char *argv[])
{
	if (argc != 1 && strcmp(argv[1], "handler_expand_test") != 0)
		return ;
	create_title("handler_expand_test");

	remove_invalid_expand_test();
	make_invalid_expand_word_test();
	make_expand_after_heredoc_word_test();

}
