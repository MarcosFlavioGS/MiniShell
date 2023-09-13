#include "test_aux.h"
#include "../include/parser/token.h"
#include "../libft/libft.h"
#include "assertz/assertz.h"

t_token *test_get_token(char *text, char *aux, t_tok_type type, char *msg_on_error)
{
	t_token *new_token;

	new_token = token_create(text, type);
	if(!new_token)
		assert_utils_die(msg_on_error);
	if (aux)
	{
		free(new_token->text_aux);
		new_token->text_aux = ft_strdup(aux);
		if (!new_token->text_aux)
			assert_utils_die(msg_on_error);
	}
	return (new_token);
}