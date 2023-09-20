#include "handler_dquotes_test.h"
#include "../../../debug/token_list_utils.h"
#include "../../../include/parser/handler_dquotes.h"
#include "../../../include/minishell.h"
#include "../../assertz/assertz.h"

static char *format = "%-45s";

static void make_inside_dquote_word_test()
{
	create_subtitle("make_inside_dquote_word_test");

	//actual
	t_token token0_act_00; token0_act_00.type = eol;     token0_act_00.next = NULL;
	t_token token0_act_01; token0_act_01.type = dquote;  token0_act_01.next = &token0_act_00;
	t_token token0_act_02; token0_act_02.type = dquote;  token0_act_02.next = &token0_act_01;

	//expected
	t_token token0_exp_00; token0_exp_00.type = eol;     token0_exp_00.next = NULL;
	t_token token0_exp_01; token0_exp_01.type = dquote;  token0_exp_01.next = &token0_exp_00;
	t_token token0_exp_02; token0_exp_02.type = dquote;  token0_exp_02.next = &token0_exp_01;

	make_inside_dquote_word(&token0_act_02);
	int is_equal = list_token_compare_type(&token0_exp_02, &token0_act_02);
	assert_svalue(0, is_equal, format, "dquote|dquote|eol");


	// ========== test 2 ==========

	//actual
	t_token token1_act_00; token1_act_00.type = eol;     token1_act_00.next = NULL;
	t_token token1_act_01; token1_act_01.type = dquote;  token1_act_01.next = &token1_act_00;
	t_token token1_act_02; token1_act_02.type = expand;  token1_act_02.next = &token1_act_01;
	t_token token1_act_03; token1_act_03.type = dquote;  token1_act_03.next = &token1_act_02;

	//expected
	t_token token1_exp_00; token1_exp_00.type = eol;     token1_exp_00.next = NULL;
	t_token token1_exp_01; token1_exp_01.type = dquote;  token1_exp_01.next = &token1_exp_00;
	t_token token1_exp_02; token1_exp_02.type = word;    token1_exp_02.next = &token1_exp_01;
	t_token token1_exp_03; token1_exp_03.type = dquote;  token1_exp_03.next = &token1_exp_02;

	make_inside_dquote_word(&token1_act_03);
	is_equal = list_token_compare_type(&token1_exp_03, &token1_act_03);
	assert_svalue(0, is_equal, format, "dquote|expand|dquote|eol");


	// ========== test 3 ==========

	//actual
	t_token token2_act_00; token2_act_00.type = eol;     token2_act_00.next = NULL;
	t_token token2_act_01; token2_act_01.type = dquote;  token2_act_01.next = &token2_act_00;
	t_token token2_act_02; token2_act_02.type = word;    token2_act_02.next = &token2_act_01;
	t_token token2_act_03; token2_act_03.type = expand;  token2_act_03.next = &token2_act_02;
	t_token token2_act_04; token2_act_04.type = dquote;  token2_act_04.next = &token2_act_03;

	//expected
	t_token token2_exp_00; token2_exp_00.type = eol;     token2_exp_00.next = NULL;
	t_token token2_exp_01; token2_exp_01.type = dquote;  token2_exp_01.next = &token2_exp_00;
	t_token token2_exp_02; token2_exp_02.type = word;    token2_exp_02.next = &token2_exp_01;
	t_token token2_exp_03; token2_exp_03.type = expand;  token2_exp_03.next = &token2_exp_02;
	t_token token2_exp_04; token2_exp_04.type = dquote;  token2_exp_04.next = &token2_exp_03;

	make_inside_dquote_word(&token2_act_04);
	is_equal = list_token_compare_type(&token2_exp_04, &token2_act_04);
	assert_svalue(0, is_equal, format, "dquote|expand|word|dquote|eol");

		// ========== test 3 ==========

	//actual
	t_token token3_act_00; token3_act_00.type = eol;     token3_act_00.next = NULL;
	t_token token3_act_01; token3_act_01.type = dquote;  token3_act_01.next = &token3_act_00;
	t_token token3_act_02; token3_act_02.type = expand;  token3_act_02.next = &token3_act_00;
	t_token token3_act_03; token3_act_03.type = pipez;   token3_act_03.next = &token3_act_00;
	t_token token3_act_04; token3_act_04.type = word;    token3_act_04.next = &token3_act_01;
	t_token token3_act_05; token3_act_05.type = expand;  token3_act_05.next = &token3_act_02;
	t_token token3_act_06; token3_act_06.type = dquote;  token3_act_06.next = &token3_act_03;

	//expected
	t_token token3_exp_00; token3_exp_00.type = eol;     token3_exp_00.next = NULL;
	t_token token3_exp_01; token3_exp_01.type = dquote;  token3_exp_01.next = &token3_exp_00;
	t_token token3_exp_02; token3_exp_02.type = word;    token3_exp_02.next = &token3_exp_00;
	t_token token3_exp_03; token3_exp_03.type = word;    token3_exp_03.next = &token3_exp_00;
	t_token token3_exp_04; token3_exp_04.type = word;    token3_exp_04.next = &token3_exp_01;
	t_token token3_exp_05; token3_exp_05.type = expand;  token3_exp_05.next = &token3_exp_02;
	t_token token3_exp_06; token3_exp_06.type = dquote;  token3_exp_06.next = &token3_exp_03;

	make_inside_dquote_word(&token3_act_06);
	is_equal = list_token_compare_type(&token3_exp_06, &token3_act_06);
	assert_svalue(0, is_equal, format, "dquote|expand|word|pipe|expand|dquote|eol");
}


//  handler_dquotes_test.c
void handler_dquotes_test(int argc, char *argv[])
{
	if (argc != 1 && strcmp(argv[1], "handler_dquotes_test") != 0)
		return ;
	create_title("handler_dquotes_test");

	make_inside_dquote_word_test();
}
