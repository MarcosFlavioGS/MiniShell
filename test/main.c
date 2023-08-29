#include "main.h"
#include "../test/assertz/assertz.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

	if (argc == 1 || strcmp(argv[1], "env_manager_test") == 0)
		env_manager_test();
	if (argc == 1 || strcmp(argv[1], "env_manager2_test") == 0)
		env_manager2_test();
	return 0;
}
