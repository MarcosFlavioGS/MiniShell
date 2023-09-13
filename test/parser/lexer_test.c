#include "../../include/minishell.h"
#include "../../include/parser/lexer.h"
#include "../../include/parser/list_token.h"
#include "../../include/parser/token.h"
#include "../../debug/token_list_utils.h"
#include "../assertz/assertz.h"
#include "../test_aux.h"

void	lexer_test()  //fazer testes
{
	int returnz;
	create_title("lexer_test");

	// ===== test1
	char *str1 = "";
	t_token *token0_act_00 = lexer_create_tokens(str1);
	if (!token0_act_00)
		assert_utils_die("malloc error! token0_act_00");

	t_token *token0_exp_00 = test_get_token("\0", NULL, eol, "token0_exp_00");

	returnz = list_token_compare(token0_exp_00, token0_act_00);
	assert_svalue(0, returnz, "eol");
	list_token_clear(&token0_act_00); list_token_clear(&token0_exp_00);

	// ===== test2
	char *str2 = "";
	t_token *token1_act_00 = lexer_create_tokens(str2);
	if (!token1_act_00)
		assert_utils_die("malloc error! token0_act_00");

	t_token *token1_exp_00 = test_get_token("\0", NULL, eol, "token1_exp_00");

	returnz = list_token_compare(token1_exp_00, token1_act_00);
	assert_svalue(0, returnz, "eol");
	list_token_clear(&token1_act_00); list_token_clear(&token1_exp_00);
}
