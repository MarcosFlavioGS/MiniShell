#include "../../../include/minishell.h"
#include "../../../include/parser/grammar/grammar.h"

int	grammar_append(t_token *token_redir_append, t_grammar *grammar)
{
	if (token_redir_append->next->type != word)
	{
		print_syntax_err(token_redir_append->next->type);
		grammar->is_grammar_err = 1;
	}
	grammar->count += 2;
}
