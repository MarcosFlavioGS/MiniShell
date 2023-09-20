#include "parser_test.h"
#include "../../../include/parser/parser.h"
#include "../../assertz/assertz.h"

void parser_test(int argc, char *argv[])
{
	if (argc != 1 && strcmp(argv[1], "parser_test") != 0)
		return ;

	create_title("parser_test");

	char *env[] = {"a=foo", "b=bar", NULL};
	t_mini mini;
	mini.command_list = NULL;
	mini.env = env;
	mini.last_exit_code = 42;
	mini.line = NULL;
	mini.token_list = NULL;

	//char *string = ">oi\"oi\"oi \"\" $a $? $xuxu\"\" << $oi$xuxu $? $=oi  $a=file  $xuxu=file2 $$$   $fsfs=.txt $zzz";

	char *string = "> oi >> oi2 << oi3 < oi4 $a $x | $? word1 word2 << $dolar_vira_word$d_vira_w  <<<";
	parser(&mini, string);
}