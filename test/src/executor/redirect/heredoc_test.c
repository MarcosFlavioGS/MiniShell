#include "heredoc_test.h"
#include "../../../../include/executor/redirect/heredoc.h"

#include "../../../../include/minishell.h"
#include "../../../assertz/assertz.h"

# include <stdio.h>
# include <string.h>
# include <unistd.h>

void	heredoc_test(int argc, char *argv[])
{
	if (argc != 1 &&  strcmp(argv[1], "heredoc_test") != 0)
		return ;
	create_title("heredoc_test");

	int fd = make_heredoc("EOF");
	printf("fd %d\n", fd);
	char	buffer[2];
	memset(buffer, 0, 2);
	read(fd, buffer, 1);
	printf("readed: %s\n", buffer);
	if (close(fd) == -1)
	{
		perror("fd close");
		assert_utils_die("fd close");
	}

	int fd2 = make_heredoc("EOF");
	printf("2 fd %d\n", fd2);
	read(fd2, buffer, 1);
	printf("2 readed: %s\n", buffer);
	if (close(fd2) == -1)
	{
		perror("fd close");
		assert_utils_die("fd close");
	}
}