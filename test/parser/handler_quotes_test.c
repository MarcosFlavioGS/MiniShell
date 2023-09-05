#include "../../include/parser/handler_quotes.h"
#include "../../debug/token_list_utils.h"
#include "../../include/minishell.h"
#include "../../include/parser/token.h"
#include "../../include/parser/list_token.h"
#include "../assertz/assertz.h"
#include "../test_aux.h"

static char *format = "%-45s";

void	add_empty_string_test()
{
	int	returnz, is_equal;

	create_subtitle("add_empty_string_test");

	// ==== test 1 ====
	t_token	*l01_at00 = test_get_token("\0", NULL, eol,    "l01_at00");
	t_token	*l01_at01 = test_get_token("\"", NULL, dquote, "l01_at01"); l01_at01->next = l01_at00;
	t_token	*l01_at02 = test_get_token("\"", NULL, dquote, "l01_at02"); l01_at02->next = l01_at01;

	t_token	*l01_ex00 = test_get_token("\0", NULL, eol,    "l01_ex00");
	t_token	*l01_ex01 = test_get_token("\"", NULL, dquote, "l01_ex01"); l01_ex01->next = l01_ex00;
	t_token	*l01_ex02 = test_get_token("",   NULL, word,   "l01_ex02"); l01_ex02->next   = l01_ex01;
	t_token	*l01_ex03 = test_get_token("\"", NULL, dquote, "l01_ex03"); l01_ex03->next = l01_ex02;

	returnz  = add_empty_string(&l01_at02);
	is_equal = list_token_compare(l01_ex03, l01_at02);
	assert_svalue(0, is_equal, format, "dquote|word|dquote|eol (dquote)");
	list_token_clear(&l01_at02); 	list_token_clear(&l01_ex03);

	// ==== test 2 ====
	t_token	*l02_at00 = test_get_token("\0", NULL, eol,    "l02_at00");
	t_token	*l02_at01 = test_get_token("\'", NULL, squote, "l02_at01"); l02_at01->next = l02_at00;
	t_token	*l02_at02 = test_get_token("\'", NULL, squote, "l02_at02"); l02_at02->next = l02_at01;

	t_token	*l02_ex00 = test_get_token("\0", NULL, eol,    "l02_ex00");
	t_token	*l02_ex01 = test_get_token("\'", NULL, squote, "l02_ex01"); l02_ex01->next = l02_ex00;
	t_token	*l02_ex02 = test_get_token("",   NULL, word,   "l02_ex02"); l02_ex02->next   = l02_ex01;
	t_token	*l02_ex03 = test_get_token("\'", NULL, squote, "l02_ex03"); l02_ex03->next = l02_ex02;

	returnz  = add_empty_string(&l02_at02);
	is_equal = list_token_compare(l02_ex03, l02_at02);
	assert_svalue(0, is_equal, format, "dquote|word|dquote|eol (squote)");
	list_token_clear(&l02_at02); 	list_token_clear(&l02_ex03);

	// ==== test 3 ====
	t_token	*l03_at00 = test_get_token("\0", NULL, eol,    "l03_at00");
	t_token	*l03_at01 = test_get_token("\"", NULL, dquote, "l03_at01"); l03_at01->next = l03_at00;
	t_token	*l03_at02 = test_get_token("\'", NULL, squote, "l03_at02"); l03_at02->next = l03_at01;
	t_token	*l03_at03 = test_get_token("\"", NULL, dquote, "l03_at03"); l03_at03->next = l03_at02;

	t_token	*l03_ex00 = test_get_token("\0", NULL, eol,    "l03_ex00");
	t_token	*l03_ex01 = test_get_token("\"", NULL, dquote, "l03_ex01"); l03_ex01->next = l03_ex00;
	t_token	*l03_ex02 = test_get_token("\'", NULL, squote, "l03_ex02"); l03_ex02->next = l03_ex01;
	t_token	*l03_ex03 = test_get_token("",   NULL, word,   "l03_ex03"); l03_ex03->next = l03_ex02;
	t_token	*l03_ex04 = test_get_token("\"", NULL, dquote, "l03_ex04"); l03_ex04->next = l03_ex03;

	returnz  = add_empty_string(&l03_at03);
	is_equal = list_token_compare(l03_ex04, l03_at03);
	assert_svalue(0, is_equal, format, "dquote|word|squote|dquote|eol (dquote)");
	list_token_clear(&l03_at03); 	list_token_clear(&l03_ex04);

	// ==== test 4 ====
	t_token	*l04_at00 = test_get_token("\0", NULL, eol,    "l04_at00");
	t_token	*l04_at01 = test_get_token("\'", NULL, squote, "l04_at01"); l04_at01->next = l04_at00;
	t_token	*l04_at02 = test_get_token("\"", NULL, dquote, "l04_at02"); l04_at02->next = l04_at01;
	t_token	*l04_at03 = test_get_token("\'", NULL, squote, "l04_at03"); l04_at03->next = l04_at02;

	t_token	*l04_ex00 = test_get_token("\0", NULL, eol,    "l04_ex00");
	t_token	*l04_ex01 = test_get_token("\'", NULL, squote, "l04_ex01"); l04_ex01->next = l04_ex00;
	t_token	*l04_ex02 = test_get_token("\"", NULL, dquote, "l04_ex02"); l04_ex02->next = l04_ex01;
	t_token	*l04_ex03 = test_get_token("",   NULL, word,   "l04_ex03");  l04_ex03->next = l04_ex02;
	t_token	*l04_ex04 = test_get_token("\'", NULL, squote, "l04_ex04"); l04_ex04->next = l04_ex03;

	returnz  = add_empty_string(&l04_at03);
	is_equal = list_token_compare(l04_ex04, l04_at03);
	assert_svalue(0, is_equal, format, "squote|word|dquote|squote|eol (squote)");
	list_token_clear(&l04_at03); 	list_token_clear(&l04_ex04);
}

static void	remove_quotes_test()
{
	int	returnz, is_equal;

	create_subtitle("remove_quotes_test");

	// ==== test 1 ====
	t_token	*l01_at00 = test_get_token("\0", NULL, eol,    "l01_at00");
	t_token	*l01_at01 = test_get_token("\"", NULL, dquote, "l01_at01"); l01_at01->next = l01_at00;
	t_token	*l01_at02 = test_get_token("\'", NULL, squote, "l01_at02"); l01_at02->next = l01_at01;

	t_token	*l01_ex00 = test_get_token("\0", NULL, eol, "l01_ex00");

	returnz  = remove_quotes(&l01_at02);
	is_equal = list_token_compare(l01_ex00, l01_at02);
	assert_svalue(0, returnz, format,  "l01_at00 return");
	assert_svalue(0, is_equal, format, "l01_at00 eol");
	list_token_clear(&l01_at02); 	list_token_clear(&l01_ex00);
}
//	handler_separators_test.c
void handler_quotes_test()
{
	create_title("handler_quotes_test");

	add_empty_string_test();
	remove_quotes_test();
}
