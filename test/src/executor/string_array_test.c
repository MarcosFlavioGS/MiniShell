#include "string_array_test.h"
#include "../../../include/executor/string_array.h"
#include "../../../include/minishell.h"
#include "../../assertz/assertz.h"

void string_array_test(int argc, char *argv[])
{
	if (argc != 1 &&  strcmp(argv[1], "string_array_test") != 0)
		return ;

	create_title("string_array_test");

	char **str_arr_1 = NULL;
	char *str_1     =  ft_strdup("foo");
	if (!str_1)
		assert_utils_die("str_1");

	string_array_add(&str_arr_1, str_1);
	assert_string("foo", str_arr_1[0], "str_arr_1");
	string_array_free(str_arr_1);
	assert_utils_separator();


	char **str_arr_2 = NULL;
	char *str_2_0     =  ft_strdup("foo");
	if (!str_2_0)
		assert_utils_die("str_2_0");
	char *str_2_1     =  ft_strdup("bar");
	if (!str_2_1)
		assert_utils_die("str_2_1");
	assert_svalue(0, string_array_add(&str_arr_2, str_2_0), "str_arr_2 add 1");
	assert_svalue(0, string_array_add(&str_arr_2, str_2_1), "str_arr_2 add 2");
	assert_string("foo", str_arr_2[0], "str_arr_2[0]");
	assert_string("bar", str_arr_2[1], "str_arr_2[1]");
	string_array_free(str_arr_2);
}
