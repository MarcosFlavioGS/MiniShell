#include "main.h"
#include "../mini_shell.h"
#include "assertz/assertz.h"

static void	env_dup_test()
{
	create_subtitle("env_dup_test");

	char *test[] = { "string1", "string2", 0};

	char **new_env = env_dup(test);

	assert_string(test[0], new_env[0], "string1");
	assert_string(test[1], new_env[1], "string2");
	assert_string(test[2], new_env[2], "null");

	env_free(new_env);
}

static void env_get_value_test()
{
	int status = 0;

	create_subtitle("env_get_value_test");

	char *test1[] = {0};
	char *test1_return1 = env_get_value(test1, "foo", &status);
	assert_string(NULL, test1_return1, "test1_return1 (null)");
	assert_svalue(0, status, "test1_return1 status");

	//test 2
	char *test2[] = {"a=", 0};
	char *test2_return1 = env_get_value(test2, "a", &status);
		assert_string("", test2_return1, "test2_return1 env_get_value(a) (empty string)");
		assert_svalue(0, status, "test2_return1 env_get_value(a) status");
		free(test2_return1);
	char *test2_return2 = env_get_value(test2, "b", &status);
		assert_string(NULL, test2_return2, "test2_return2 env_get_value(b) (null)");
		assert_svalue(0, status, "test2_return2 env_get_value(b) status");

	//test 3
	char *test3[] = {"a=foo", 0};
	char *test3_return1 = env_get_value(test3, "a", &status);
		assert_string("foo", test3_return1, "test3_return1 env_get_value(a) (foo)");
		assert_svalue(0, status, "test3_return1 env_get_value(a) status");
		free(test3_return1);

	//test 4
	char *test4[] = {"a=foo", "foo=bar", 0};
	char *test4_return1 = env_get_value(test4, "foo", &status);
		assert_string("bar", test4_return1, "test4_return1 env_get_value(foo) (bar)");
		assert_svalue(0, status, "test4_return1 env_get_value(foo) status");
		free(test4_return1);

	//test 5
	char *test5[] = {"a=foo", "foo=bar=z", 0};
	char *test5_return1 = env_get_value(test5, "foo", &status);
		assert_string("bar=z", test5_return1, "test5_return1 env_get_value(foo) (bar=z)");
		assert_svalue(0, status, "test5_return1 env_get_value(foo) status");
		free(test5_return1);

}

void env_manager_test()
{
	create_title("env_manager_test");

	env_dup_test();
	env_get_value_test();
}