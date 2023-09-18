#include "syntax_list_test.h"
#include "../../../include/parser/syntax_list.h"
#include "../../../include/parser/list_token.h"


#include "../../../debug/token_list_utils.h"

void syntax_list_test(int argc, char *argv[])
{
	if (argc != 1 && strcmp(argv[1], "syntax_list_test") != 0)
		return ;
	char *env[] = {"a=foo", "b=bar", NULL};
	t_mini mini;
	mini.last_exit_code = 42;
	mini.env = env;
	mini.token_list = NULL;

	//char *string = "> oi >> oi2 << oi3 < oi4 $a $x | $? word1 word2 << $dolar_vira_word$d_vira_w  <<< a\"  \"b \"\'\"\'\"\' \"";
	//syntax_list(&mini);

	//list_token_printf(mini.token_list);
	//llist_token_clear(&mini.token_list);

}