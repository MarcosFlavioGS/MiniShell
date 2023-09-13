#include "../../include/parser/parser.h"

void parser_test()
{
	char *env[] = {"a=foo", "b=bar", NULL};
	t_mini mini;
	mini.last_exit_code = 42;
	mini.env = env;

	//char *string = ">oi\"oi\"oi \"\" $a $? $xuxu\"\" << $oi$xuxu $? $=oi  $a=file  $xuxu=file2 $$$   $fsfs=.txt $zzz";

	char *string = "> oi >> oi2 << oi3 < oi4 $a $x | $? word1 word2 << $dolar_vira_word$d_vira_w  <<<";
	parser(&mini, string);
}