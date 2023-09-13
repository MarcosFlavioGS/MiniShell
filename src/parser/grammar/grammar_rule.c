#include "../../../include/minishell.h"
#include "../../../include/parser/grammar/grammar.h"

int	grammar_word(t_token *token_word, t_grammar *grammar)
{
	grammar->count++;
}

int	grammar_pipez(t_token *token_pipez, t_grammar *grammar)
{
	if (grammar->count == 0 || token_pipez->next->type == eol
		|| token_pipez->next->type == pipez)
	{
		print_syntax_err(pipez);
		grammar->is_grammar_err = 1;
	}
	grammar->count++;
}

int	grammar_redir_in(t_token *token_redir_in, t_grammar *grammar)
{
	if (token_redir_in->next->type != word)
	{
		print_syntax_err(token_redir_in->next->type);
		grammar->is_grammar_err = 1;
	}
	grammar->count += 2;
}

int	grammar_redir_out(t_token *token_redir_out, t_grammar *grammar)
{
	if (token_redir_out->next->type != word)
	{
		print_syntax_err(token_redir_out->next->type);
		grammar->is_grammar_err = 1;
	}
	grammar->count += 2;
}

int	grammar_heredoc(t_token *token_redir_heredoc, t_grammar *grammar)
{
	if (token_redir_heredoc->next->type != word)
	{
		print_syntax_err(token_redir_heredoc->next->type);
		grammar->is_grammar_err = 1;
	}
	grammar->count += 2;
}
