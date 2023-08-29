#include "main.h"
#include "../mini_shell.h"
#include "assertz/assertz.h"

static void env_add_value_test()
{
	int returnz = 0;
	create_subtitle("env_add_value_test");

	// ==== test 1
	char *empty_env1[] = {0};
	char **m_empty_env1 = env_dup(empty_env1);
	returnz = env_add_value(&m_empty_env1, "");
		assert_svalue(ENV_INVLD_PARAM, returnz, "m_empty_env1 add: (empty string)");
		assert_string(NULL, m_empty_env1[0], "m_empty_env1[0] == NULL");
	returnz = env_add_value(&m_empty_env1, "=a");
		assert_svalue(ENV_INVLD_PARAM, returnz, "m_empty_env1 add:  =a");
		assert_string(NULL, m_empty_env1[0], "m_empty_env1[0] == NULL");
	env_free(m_empty_env1);
	printf("-----\n");

	// ==== test 2
	char *empty_env2[] = {0};
	char **m_empty_env2 = env_dup(empty_env2);
	returnz = env_add_value(&m_empty_env2, "a="); //test add new value with empty list
		assert_svalue(0, returnz, "m_empty_env2 add: a=");
		assert_string("a=", m_empty_env2[0], "m_empty_env2[0] == a=");
		assert_string(NULL, m_empty_env2[1], "m_empty_env2[0] == NULL");
	returnz = env_add_value(&m_empty_env2, "a=b"); //test add a exiting value
		assert_string("a=b", m_empty_env2[0], "m_empty_env2[0] == a=b");
		assert_string(NULL, m_empty_env2[1], "m_empty_env2[0] == NULL (2)");
	returnz = env_add_value(&m_empty_env2, "foo=bar"); //test add new value with not empty list
		assert_string("a=b", m_empty_env2[0], "m_empty_env2[0] == a=b");
		assert_string("foo=bar", m_empty_env2[1], "m_empty_env2[1] == foo=bar");
		assert_string(NULL, m_empty_env2[2], "m_empty_env2[2] == NULL (2)");
	env_free(m_empty_env2);
}

void env_remove_value_test()
{
	int returnz = 0;
	create_subtitle("env_remove_value_test");

	// ==== test 1
	char *empty_env1[] = {0};
	char **m_empty_env1 = env_dup(empty_env1);
	returnz =  env_remove_value(&m_empty_env1, "foo");
		assert_svalue(0, returnz, "return from m_empty_env1 remove: foo");
	env_free(m_empty_env1);
	printf("-----\n");

	// ==== test 2
	char *empty_env2[] = {"a=foo", 0};
	char **m_empty_env2 = env_dup(empty_env2);
		assert_string("a=foo", m_empty_env2[0], "m_empty_env2[0] == [a=foo] before remove");
	returnz =  env_remove_value(&m_empty_env2, "a");
		assert_svalue(0, returnz, "return from m_empty_env2 remove: a");
		assert_string(NULL, m_empty_env2[0], "m_empty_env2[0] == [NULL] after remove");
	env_free(m_empty_env2);
	printf("-----\n");

	// ==== test 3.1 remove fist item
	char *empty_env3[] = {"a=foo", "b=bar", 0};
	char **m_empty_env3 = env_dup(empty_env3);
		assert_string("a=foo", m_empty_env3[0], "m_empty_env3[0] == [a=foo] before remove");
		assert_string("b=bar", m_empty_env3[1], "m_empty_env3[1] == [b=bar] before remove");
		assert_string(NULL,	   m_empty_env3[2], "m_empty_env3[2] == NULL before remove");
	returnz =  env_remove_value(&m_empty_env3, "a");
		assert_svalue(0, returnz, "return from m_empty_env3 remove: a");
		assert_string("b=bar", m_empty_env3[0], "m_empty_env3[0] == [b=bar] after remove");
		assert_string(NULL, m_empty_env3[1], "m_empty_env3[1] == NULL after remove");
	env_free(m_empty_env3);
	printf("-----\n");

	// ==== test 3.2 remove last item
	char *empty_env4[] = {"a=foo", "b=bar", 0};
	char **m_empty_env4 = env_dup(empty_env4);
		assert_string("a=foo", m_empty_env4[0], "m_empty_env4[0] == [a=foo] before remove");
		assert_string("b=bar", m_empty_env4[1], "m_empty_env4[1] == [b=bar] before remove");
		assert_string(NULL,	   m_empty_env4[2], "m_empty_env4[2] == NULL before remove");
	returnz =  env_remove_value(&m_empty_env4, "b");
		assert_svalue(0, returnz, "return from m_empty_env4 remove: b");
		assert_string("a=foo", m_empty_env4[0], "m_empty_env4[0] == [a=foo] after remove");
		assert_string(NULL, m_empty_env4[1], "m_empty_env4[1] == NULL after remove");
	env_free(m_empty_env4);
	printf("-----\n");

	// ==== test 3.2 remove not existing item
	char *empty_env5[] = {"a=foo", "b=bar", 0};
	char **m_empty_env5 = env_dup(empty_env5);
		assert_string("a=foo", m_empty_env5[0], "m_empty_env5[0] == [a=foo] before remove");
		assert_string("b=bar", m_empty_env5[1], "m_empty_env5[1] == [b=bar] before remove");
		assert_string(NULL,	   m_empty_env5[2], "m_empty_env5[2] == NULL before remove");
	returnz =  env_remove_value(&m_empty_env5, "c");
		assert_svalue(0, returnz, "return from m_empty_env5 remove: c");
		assert_string("a=foo", m_empty_env5[0], "m_empty_env5[0] == [a=foo] after remove");
		assert_string("b=bar", m_empty_env5[1], "m_empty_env5[1] == [b=bar] after remove");
		assert_string(NULL,	   m_empty_env5[2], "m_empty_env5[2] == NULL after remove");
	env_free(m_empty_env5);
}

void env_manager2_test()
{
	create_title("env_manager2_test");

	env_add_value_test();
	env_remove_value_test();
}