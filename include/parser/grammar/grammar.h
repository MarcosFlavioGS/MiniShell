#include "../../../include/minishell.h"
#include "../../../include/utils/message.h"

//  the grammar methods
int		grammar_word(t_token *token_word, t_grammar *grammar);

int		grammar_pipez(t_token *token_pipez, t_grammar *grammar);

int		grammar_redir_in(t_token *token_redir_in, t_grammar *grammar);

int		grammar_redir_out(t_token *token_redir_out, t_grammar *grammar);

int		grammar_heredoc(t_token *token_redir_heredoc, t_grammar *grammar);

int		grammar_append(t_token *token_redir_append, t_grammar *grammar);


//  other methods
void	print_syntax_err(t_tok_type token_type);

int		check_grammar(t_token *token_list);