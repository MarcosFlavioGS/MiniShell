#include "../../include/minishell.h"
#include "../../include/parser/handler_separators.h"
#include "../../include/parser/token.h"
#include "../../include/parser/list_token.h"
#include "../../debug/token_list_utils.h"
#include "../assertz/assertz.h"
#include "../test_aux.h"

static char *format = "%-40s";

static void list0()
{
	create_subtitle("list0");

	t_token	*l00_at00 = test_get_token("\0", NULL, eol, "l00_at00");

	t_token	*l00_ex00 = test_get_token("\0", NULL, eol, "l00_ex00");

	remove_invalid_separators(&l00_at00);

	int is_equal = list_token_compare(l00_ex00, l00_at00);
	assert_svalue(0, is_equal, format, "eol");

	list_token_clear(&l00_at00);
	list_token_clear(&l00_ex00);
}

static void list1_0()
{
	create_subtitle("list1_0");

	t_token	*l00_at00 = test_get_token("\0",  NULL, eol,  "l00_at00");
	t_token	*l00_at01 = test_get_token("Abc", NULL, word, "l00_at01"); l00_at01->next = l00_at00;

	t_token	*l00_ex00 = test_get_token("\0",  NULL, eol,  "l00_ex00");
	t_token	*l00_ex01 = test_get_token("Abc", NULL, word, "l00_ex01"); l00_ex01->next = l00_ex00;

	remove_invalid_separators(&l00_at01);

	int is_equal = list_token_compare(l00_ex01, l00_at01);
	assert_svalue(0, is_equal, format, "word|eol");

	list_token_clear(&l00_at01);
	list_token_clear(&l00_ex01);
}

static void list1_1()
{

	create_subtitle("list1_1");

	t_token	*l00_at00 = test_get_token(" ", NULL,  word, "l00_at00");
	t_token	*l00_at01 = test_get_token("\0", NULL, eol, "l00_at01"); l00_at01->next = l00_at00;

	t_token	*l00_ex00 = test_get_token(" ", NULL, word, "l00_ex00");
	t_token	*l00_ex01 = test_get_token("\0", NULL, eol, "l00_ex01"); l00_ex01->next = l00_ex00;

	remove_invalid_separators(&l00_at01);

	int is_equal = list_token_compare(l00_ex01, l00_at01);
	assert_svalue(0, is_equal, format, "separator|eol");

	list_token_clear(&l00_at01);
	list_token_clear(&l00_ex01);
}

static void list1()
{

	create_subtitle("list1");

	t_token	*l00_at00 = test_get_token("\0", NULL, eol,       "l00_at00");
	t_token	*l00_at01 = test_get_token("\"", NULL, dquote,    "l00_at01"); l00_at01->next = l00_at00;
	t_token	*l00_at02 = test_get_token("  ", NULL, separator, "l00_at02"); l00_at02->next = l00_at01;

	t_token	*l00_ex00 = test_get_token("\0", NULL, eol,       "l00_ex00");
	t_token	*l00_ex01 = test_get_token("\"", NULL, dquote,    "l00_ex01"); l00_ex01->next = l00_ex00;

	remove_invalid_separators(&l00_at02);

	int is_equal = list_token_compare(l00_ex01, l00_at02);
	assert_svalue(0, is_equal,  format, "separator|dquote|eol");

	list_token_clear(&l00_at02);
	list_token_clear(&l00_ex01);
}

static void list2()
{

	create_subtitle("list2");

	t_token	*l00_at00 = test_get_token("\0", NULL, eol,       "l00_at00");
	t_token	*l00_at01 = test_get_token("  ", NULL, separator, "l00_at01"); l00_at01->next = l00_at00;
	t_token	*l00_at02 = test_get_token("\"", NULL, dquote,    "l00_at02"); l00_at02->next = l00_at01;

	t_token	*l00_ex00 = test_get_token("\0", NULL, eol,       "l00_ex00");
	t_token	*l00_ex01 = test_get_token("  ", NULL, separator, "l00_ex01"); l00_ex01->next = l00_ex00;
	t_token	*l00_ex02 = test_get_token("\"", NULL, dquote,    "l00_ex02"); l00_ex02->next = l00_ex01;

	remove_invalid_separators(&l00_at02);

	int is_equal = list_token_compare(l00_ex02, l00_at02);
	assert_svalue(0, is_equal, format, "dquote|eol");

	list_token_clear(&l00_at02);
	list_token_clear(&l00_ex02);
}

static void list3()
{

	create_subtitle("list3");

	t_token	*l00_at00 = test_get_token("\0", NULL, eol,       "l00_at00");
	t_token	*l00_at01 = test_get_token("  ", NULL, separator, "l00_at01"); l00_at01->next = l00_at00;
	t_token	*l00_at02 = test_get_token("\"", NULL, dquote,    "l00_at02"); l00_at02->next = l00_at01;
	t_token	*l00_at03 = test_get_token("  ", NULL, separator, "l00_at03"); l00_at03->next = l00_at02;
	t_token	*l00_at04 = test_get_token("\"", NULL, dquote,    "l00_at04"); l00_at04->next = l00_at03;

	t_token	*l00_ex00 = test_get_token("\0", NULL, eol,       "l00_ex00");
	t_token	*l00_ex01 = test_get_token("\"", NULL, dquote,    "l00_ex01"); l00_ex01->next = l00_ex00;
	t_token	*l00_ex02 = test_get_token("  ", NULL, separator, "l00_ex02"); l00_ex02->next = l00_ex01;
	t_token	*l00_ex03 = test_get_token("\"", NULL, dquote,    "l00_ex03"); l00_ex03->next = l00_ex02;

	remove_invalid_separators(&l00_at04);

	int is_equal = list_token_compare(l00_ex03, l00_at04);
	assert_svalue(0, is_equal, format, "dquote|separator|dquote|separator|eol");

	list_token_clear(&l00_at04);
	list_token_clear(&l00_ex03);
}

static void list4()
{

	create_subtitle("list4");

	t_token	*l00_at00 = test_get_token("\0", NULL, eol,       "l00_at00");
	t_token	*l00_at01 = test_get_token("  ", NULL, separator, "l00_at01"); l00_at01->next = l00_at00;
	t_token	*l00_at02 = test_get_token("\'", NULL, squote,    "l00_at02"); l00_at02->next = l00_at01;
	t_token	*l00_at03 = test_get_token("  ", NULL, separator, "l00_at03"); l00_at03->next = l00_at02;
	t_token	*l00_at04 = test_get_token("ab", NULL, word,      "l00_at04"); l00_at04->next = l00_at03;
	t_token	*l00_at05 = test_get_token("\'", NULL, squote,    "l00_at05"); l00_at05->next = l00_at04;

	t_token	*l00_at06 = test_get_token("  ", NULL, separator, "l00_at06"); l00_at06->next = l00_at05;//-------- can't remove it!

	t_token	*l00_at07 = test_get_token("\'", NULL, squote,    "l00_at07"); l00_at07->next = l00_at06;
	t_token	*l00_at08 = test_get_token("  ", NULL, separator, "l00_at08"); l00_at08->next = l00_at07;
	t_token	*l00_at09 = test_get_token("ab", NULL, word,      "l00_at09"); l00_at09->next = l00_at08;
	t_token	*l00_at10=  test_get_token("\'", NULL,  squote,   "l00_at10"); l00_at10->next = l00_at09;
	t_token	*l00_at11 = test_get_token("\"", NULL, dquote,    "l00_at11"); l00_at11->next = l00_at10;
	t_token	*l00_at12 = test_get_token("  ", NULL, separator, "l00_at12"); l00_at12->next = l00_at11;
	t_token	*l00_at13 = test_get_token("\"", NULL, dquote,    "l00_at13"); l00_at13->next = l00_at12;
	t_token	*l00_at14 = test_get_token("<<", NULL, heredoc,   "l00_at14"); l00_at14->next = l00_at13;
	t_token	*l00_at15 = test_get_token("  ", NULL, separator, "l00_at15"); l00_at15->next = l00_at14;


	t_token	*l00_ex00 = test_get_token("\0", NULL, eol,       "l00_ex00");
	t_token	*l00_ex01 = test_get_token("\'", NULL, squote,    "l00_ex01"); l00_ex01->next = l00_ex00;
	t_token	*l00_ex02 = test_get_token("  ", NULL, separator, "l00_ex02"); l00_ex02->next = l00_ex01;
	t_token	*l00_ex03 = test_get_token("ab", NULL, word,      "l00_ex03"); l00_ex03->next = l00_ex02;
	t_token	*l00_ex04 = test_get_token("\'", NULL, squote,    "l00_ex04"); l00_ex04->next = l00_ex03;
	t_token	*l00_ex05 = test_get_token("  ", NULL, separator, "l00_ex05"); l00_ex05->next = l00_ex04; //--------
	t_token	*l00_ex06 = test_get_token("\'", NULL, squote,    "l00_ex06"); l00_ex06->next = l00_ex05;
	t_token	*l00_ex07 = test_get_token("  ", NULL, separator, "l00_ex07"); l00_ex07->next = l00_ex06;
	t_token	*l00_ex08 = test_get_token("ab", NULL, word,      "l00_ex08"); l00_ex08->next = l00_ex07;
	t_token	*l00_ex09 = test_get_token("\'", NULL, squote,    "l00_ex09"); l00_ex09->next = l00_ex08;
	t_token	*l00_ex10 = test_get_token("\"", NULL, dquote,    "l00_ex10"); l00_ex10->next = l00_ex09;
	t_token	*l00_ex11 = test_get_token("  ", NULL, separator, "l00_ex11"); l00_ex11->next = l00_ex10;
	t_token	*l00_ex12 = test_get_token("\"", NULL, dquote,    "l00_ex12"); l00_ex12->next = l00_ex11;
	t_token	*l00_ex13 = test_get_token("<<", NULL, heredoc,   "l00_ex13"); l00_ex13->next = l00_ex12;

	remove_invalid_separators(&l00_at15);

	int is_equal = list_token_compare(l00_ex13, l00_at15);
	assert_svalue(0, is_equal, format, "    <<\"_\"\'ab_\'_\'ab_\'");

	list_token_clear(&l00_at15);
	list_token_clear(&l00_ex13);
}

static void list5()
{

	create_subtitle("list5");

	t_token	*l00_at00 = test_get_token("\0", NULL, eol,       "l00_at00");
	t_token	*l00_at01 = test_get_token("\"", NULL, dquote,    "l00_at01"); l00_at01->next = l00_at00;
	t_token	*l00_at02 = test_get_token("  ", NULL, separator, "l00_at02"); l00_at02->next = l00_at01;
	t_token	*l00_at03 = test_get_token("\'", NULL, squote,    "l00_at03"); l00_at03->next = l00_at02;
	t_token	*l00_at04 = test_get_token("\"", NULL, dquote,    "l00_at04"); l00_at04->next = l00_at03;

	t_token	*l00_ex00 = test_get_token("\0", NULL, eol,       "l00_ex00");
	t_token	*l00_ex01 = test_get_token("\"", NULL, dquote,    "l00_ex01"); l00_ex01->next = l00_ex00;
	t_token	*l00_ex02 = test_get_token("  ", NULL, separator, "l00_ex02"); l00_ex02->next = l00_ex01;
	t_token	*l00_ex03 = test_get_token("\'", NULL, squote,    "l00_ex03"); l00_ex03->next = l00_ex02;
	t_token	*l00_ex04 = test_get_token("\"", NULL, dquote,    "l00_ex04"); l00_ex04->next = l00_ex03;

	remove_invalid_separators(&l00_at04);

	int is_equal = list_token_compare(l00_ex04, l00_at04);
	assert_svalue(0, is_equal, format, "dquote|squote|separetor|dquote|eol");

	list_token_clear(&l00_at04);
	list_token_clear(&l00_ex04);
}


//	handler_separators_test.c
void handler_separators_test()
{
	create_title("handler_separators_test");

	list0();
	list1_0();
	list1_1();
	list1();
	list2();
	list3();
	list4();
	list5();
}
