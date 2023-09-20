#include <readline/readline.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int continuez = 1;

void	signal_reset_prompt(int signo)
{
	(void)signo;
	continuez = 0;
	write(1, "\n", 1);
	rl_on_new_line();
	close(0);
}

void	set_signals_interactive(void)
{
	struct sigaction	act;

	memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_reset_prompt;
	sigaction(SIGINT, &act, NULL);
}


int main(void)
{
	char *line;
	int		input_buckup = dup(0);//
	set_signals_interactive();
	printf("heredoc====\n");
	while(continuez)
	{
		line = readline("> ");
		if (line)
		{
			free(line);
			printf("[%s]", line);
		}
		else
			break ;
	}
		dup(input_buckup);
	printf("heredoc====\n");
	line = readline("> ");
	printf("[%s]", line);
}