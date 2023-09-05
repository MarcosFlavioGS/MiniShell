#include "../../include/utils/message.h"
#include <unistd.h>

int main(void)
{
	msg_fatal_err("zzzzzzz");

	int err_code = close(5);
	if(err_code == -1)
		msg_syscall_err("yyyyyyyyy");
	return 0;
}