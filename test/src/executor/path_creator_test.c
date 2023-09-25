#include "path_creator_test.h"
#include "../../../include/executor/path_creator.h"
#include "../../assertz/assertz.h"
#include <string.h>
#include <stdlib.h>

static void create_full_path_test()
{
	create_subtitle("create_full_path_test");

	char *path_full = create_full_path("a", "b");
	if (!path_full)
		assert_utils_die("create_full_path create path full");
	assert_svalue(0, strcmp(path_full, "a/b"), "a/b");
	free(path_full);

}

static void check_path_binary_test()
{
	create_subtitle("check_path_binary_test");

	int malloc_status;
	char *paths[] = {"/foo", "/usr/bin", NULL};
	char *cmd = "cat";

	char *full_path = check_path_binary(paths, cmd, &malloc_status);
	assert_svalue(0, malloc_status, "malloc_status");
	assert_string("/usr/bin/cat", full_path, "full path");
	free(full_path);
}

void	path_creator_test(int argc, char *argv[])
{
	if (argc != 1 && strcmp(argv[1], "path_creator_test") != 0)
		return ;
	create_title("path_creator_test");

	create_full_path_test();
	check_path_binary_test();
}