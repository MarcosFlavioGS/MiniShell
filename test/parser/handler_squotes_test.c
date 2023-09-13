#include "../../include/parser/handler_squotes.h"
#include "../../include/minishell.h"
#include "../../debug/token_list_utils.h"
#include "../assertz/assertz.h"

static char *format = "%-45s";

static void make_inside_squote_word_test()
{
	create_subtitle("make_inside_squote_word_test");

	//actual
	t_token token0_act_00; token0_act_00.type = eol;     token0_act_00.next = NULL;
	t_token token0_act_01; token0_act_01.type = squote;  token0_act_01.next = &token0_act_00;
	t_token token0_act_02; token0_act_02.type = squote;  token0_act_02.next = &token0_act_01;

	//expected
	t_token token0_exp_00; token0_exp_00.type = eol;     token0_exp_00.next = NULL;
	t_token token0_exp_01; token0_exp_01.type = squote;  token0_exp_01.next = &token0_exp_00;
	t_token token0_exp_02; token0_exp_02.type = squote;  token0_exp_02.next = &token0_exp_01;

	make_inside_squote_word(&token0_act_02);
	int is_equal = list_token_compare_type(&token0_exp_02, &token0_act_02);
	assert_svalue(0, is_equal, format, "squote|squote|eol");

	// ========== test 2 ==========

	//actual
	t_token token1_act_00; token1_act_00.type = eol;     token1_act_00.next = NULL;
	t_token token1_act_01; token1_act_01.type = squote;  token1_act_01.next = &token1_act_00;
	t_token token1_act_02; token1_act_02.type = dquote;  token1_act_02.next = &token1_act_01;
	t_token token1_act_03; token1_act_03.type = squote;  token1_act_03.next = &token1_act_02;

	//expected
	t_token token1_exp_00; token1_exp_00.type = eol;     token1_exp_00.next = NULL;
	t_token token1_exp_01; token1_exp_01.type = squote;  token1_exp_01.next = &token1_exp_00;
	t_token token1_exp_02; token1_exp_02.type = word;    token1_exp_02.next = &token1_exp_01;
	t_token token1_exp_03; token1_exp_03.type = squote;  token1_exp_03.next = &token1_exp_02;

	make_inside_squote_word(&token1_act_03);
	is_equal = list_token_compare_type(&token1_exp_03, &token1_act_03);
	assert_svalue(0, is_equal, format, "squote|dquote|squote|eol");


	// ========== test 3 ==========

	//actual
	t_token token2_act_00; token2_act_00.type = eol;     token2_act_00.next = NULL;
	t_token token2_act_01; token2_act_01.type = squote;  token2_act_01.next = &token2_act_00;
	t_token token2_act_02; token2_act_02.type = squote;  token2_act_02.next = &token2_act_01;

	//expected
	t_token token2_exp_00; token2_exp_00.type = eol;     token2_exp_00.next = NULL;
	t_token token2_exp_01; token2_exp_01.type = squote;  token2_exp_01.next = &token2_exp_00;
	t_token token2_exp_02; token2_exp_02.type = squote;  token2_exp_02.next = &token2_exp_01;

	make_inside_squote_word(&token2_act_02);
	is_equal = list_token_compare_type(&token2_exp_02, &token2_act_02);
	assert_svalue(0, is_equal, format, "squote|squote|eol");


	// ========== test 4 ==========

	//actual
	t_token token3_act_00; token3_act_00.type = eol;     token3_act_00.next = NULL;
	t_token token3_act_01; token3_act_01.type = squote;  token3_act_01.next = &token3_act_00;
	t_token token3_act_02; token3_act_02.type = dquote;  token3_act_02.next = &token3_act_01;
	t_token token3_act_03; token3_act_03.type = dquote;  token3_act_03.next = &token3_act_02;
	t_token token3_act_04; token3_act_04.type = squote;  token3_act_04.next = &token3_act_03;
	t_token token3_act_05; token3_act_05.type = word;    token3_act_05.next = &token3_act_04;

	//expected
	t_token token3_exp_00; token3_exp_00.type = eol;     token3_exp_00.next = NULL;
	t_token token3_exp_01; token3_exp_01.type = squote;  token3_exp_01.next = &token3_exp_00;
	t_token token3_exp_02; token3_exp_02.type = word;    token3_exp_02.next = &token3_exp_01;
	t_token token3_exp_03; token3_exp_03.type = word;    token3_exp_03.next = &token3_exp_02;
	t_token token3_exp_04; token3_exp_04.type = squote;  token3_exp_04.next = &token3_exp_03;
	t_token token3_exp_05; token3_exp_05.type = word;    token3_exp_05.next = &token3_exp_04;

	make_inside_squote_word(&token3_act_05);
	is_equal = list_token_compare_type(&token3_exp_05, &token3_act_05);
	assert_svalue(0, is_equal, format, "word|squote|dquote|dquote|squote|eol");

}

//	handler_squotes_test.c
void handler_squotes_test()
{
	create_title("handler_squotes_test");

	make_inside_squote_word_test();
}
