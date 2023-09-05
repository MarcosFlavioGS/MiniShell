
#include "../../../include/minishell.h"
#include "../../../include/parser/token.h"
#include "../../../include/utils/message.h"

int print_syntax_err(t_tok_type token_type)
{
	msg_err_nnl("minishell: syntax error near unexpected token `");
	if (token_type == redir_in)
		msg_err_nnl("<");
	if (token_type == redir_out)
		msg_err_nnl(">");
	if (token_type == append)
		msg_err_nnl(">>");
	if (token_type == heredoc)
		msg_err_nnl("<<");
	if (token_type == pipez)
		msg_err_nnl("|");
	if (token_type == eol)
		msg_err_nnl("newline");
	msg_err("\'");
}

int	check_token_type(t_token *token, size_t count)
{
	if (token->type == word)
		return
	if (token->type == redir_in)
	if (token->type == redir_out)
	if (token->type == append)
	if (token->type == heredoc)
	if (token->type == pipez)
}


int	check_grammar(t_token *token_list)
{
//	bash: syntax error near unexpected token `|'
//	bash: syntax error near unexpected token `newline'
	size_t	count;
	t_token	*token_aux;

	count = 0;
	token_aux = token_list;
	while (token_aux->type != eol)
	{

	}
}