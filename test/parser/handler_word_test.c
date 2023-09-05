#include "../../include/parser/handler_word.h"
#include "../../include/minishell.h"
#include "../../include/parser/list_token.h"
#include "../../debug/token_list_utils.h"
#include "../assertz/assertz.h"
#include "../test_aux.h"

static char *format = "%-45s";

static void join_words_test()
{
	int returnz, equals;

	create_subtitle("join_words_test");

	// ==== test1 ====
	t_token *l00_at00 = test_get_token("\0", NULL, eol, "l00_at00");

	t_token *l00_ex00 = test_get_token("\0", NULL, eol, "l00_ex00");

	returnz = join_words(&l00_at00);
	equals = list_token_compare(l00_ex00,l00_at00);
	assert_svalue(0, returnz, format, "eol (return)");
	assert_svalue(0, equals, format, "eol");
	list_token_clear(&l00_at00); 	list_token_clear(&l00_ex00);
	assert_utils_separator();


	// ==== test2 ====
	t_token *l01_at00 = test_get_token("\0", NULL, eol,  "l01_at00");
	t_token *l01_at01 = test_get_token("ab", NULL, word, "l01_at01"); l01_at01->next = l01_at00;

	t_token *l01_ex00 = test_get_token("\0", NULL, eol,  "l01_ex00");
	t_token *l01_ex01 = test_get_token("ab", NULL, word, "l01_ex01"); l01_ex01->next = l01_ex00;

	returnz = join_words(&l01_at01);
	equals = list_token_compare(l01_ex01, l01_at01);
	assert_svalue(0, returnz, format, "word|eol (return)");
	assert_svalue(0, equals, format, "word|eol");
	list_token_clear(&l01_at01); 	list_token_clear(&l01_ex01);
	assert_utils_separator();

	// ==== test 3-0 ====
	t_token *l02_at00 = test_get_token("\0",   NULL, eol,  "l02_at00");
	t_token *l02_at01 = test_get_token("cd",   NULL, word, "l02_at00"); l02_at01->next = l02_at00;
	t_token *l02_at02 = test_get_token("ab",   NULL, word, "l02_at00"); l02_at02->next = l02_at01;

	t_token *l02_ex00 = test_get_token("\0",   NULL, eol,  "l02_ex00");
	t_token *l02_ex01 = test_get_token("abcd", NULL, word, "l02_at00"); l02_ex01->next = l02_ex00;

	returnz = join_words(&l02_at02);
	equals = list_token_compare(l02_ex01, l02_at02);
	assert_svalue(0, returnz, format, "word|word|eol (return)");
	assert_svalue(0, equals, format, "word|word|eol");
	list_token_clear(&l02_at02); 	list_token_clear(&l02_ex01);
	assert_utils_separator();

	// ==== test 3-1 ====
	t_token *l03_at00 = test_get_token("\0",   NULL, eol,  "l03_at00");
	t_token *l03_at01 = test_get_token(NULL,   "$cd", word, "l03_at00"); l03_at01->next = l03_at00;
	t_token *l03_at02 = test_get_token("ab",   NULL, word, "l03_at00"); l03_at02->next = l03_at01;

	t_token *l03_ex00 = test_get_token("\0",   NULL, eol,  "l03_ex00");
	t_token *l03_ex01 = test_get_token("ab", "ab$cd", word, "l03_at00"); l03_ex01->next = l03_ex00;

	returnz = join_words(&l03_at02);
	equals = list_token_compare(l03_ex01, l03_at02);
	assert_svalue(0, returnz, format, "word|word(null)|eol (return)");
	assert_svalue(0, equals, format, "word|word(null)|eol");
	list_token_clear(&l03_at02); 	list_token_clear(&l03_ex01);
	assert_utils_separator();

	// ==== test 3-2 ====
	t_token *l04_at00 = test_get_token("\0",   NULL, eol,  "l04_at00");
	t_token *l04_at01 = test_get_token("cd",   NULL, word, "l04_at00"); l04_at01->next = l04_at00;
	t_token *l04_at02 = test_get_token(NULL,   "$ab", word, "l04_at00"); l04_at02->next = l04_at01;

	t_token *l04_ex00 = test_get_token("\0",   NULL, eol,  "l04_ex00");
	t_token *l04_ex01 = test_get_token("cd", "$abcd", word, "l04_at00"); l04_ex01->next = l04_ex00;

	returnz = join_words(&l04_at02);
	equals = list_token_compare(l04_ex01, l04_at02);
	assert_svalue(0, returnz, format, "word(null)|word|eol (return)");
	assert_svalue(0, equals, format, "word(null)|word|eol");
	list_token_clear(&l04_at02); 	list_token_clear(&l04_ex01);
	assert_utils_separator();

	// ==== test 3-3 ====
	t_token *l05_at00 = test_get_token("\0",    NULL, eol,  "l05_at00");
	t_token *l05_at01 = test_get_token(NULL,   "$cd", word, "l05_at00"); l05_at01->next = l05_at00;
	t_token *l05_at02 = test_get_token(NULL,   "$ab", word, "l05_at00"); l05_at02->next = l05_at01;

	t_token *l05_ex00 = test_get_token("\0",   NULL, eol,  "l05_ex00");
	t_token *l05_ex01 = test_get_token(NULL, "$ab$cd", word, "l05_at00"); l05_ex01->next = l05_ex00;

	returnz = join_words(&l05_at02);
	equals = list_token_compare(l05_ex01, l05_at02);
	assert_svalue(0, returnz, format, "word(null)|word(null)|eol (return)");
	assert_svalue(0, equals, format, "word(null)|word(null)|eol");
	list_token_clear(&l05_at02); 	list_token_clear(&l05_ex01);
	assert_utils_separator();
}

//	handler_word_test.c
void	handler_word_test()
{
	create_title("handler_word_test");

	join_words_test();
}