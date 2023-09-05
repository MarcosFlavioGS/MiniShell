#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../include/minishell.h"
#include "../../include/parser/handler_expand.h"
#include "../../include/parser/handler_quotes.h"
#include "../../include/parser/handler_squotes.h"
#include "../../include/parser/handler_dquotes.h"
#include "../../include/parser/handler_separators.h"
#include "../../include/parser/handler_word.h"
#include "../../include/parser/lexer.h"
#include "../../include/parser/list_token.h"
#include "../../include/parser/token.h"
#include "../../libft/libft.h"


#include "../../debug/token_list_utils.h"


static int	is_token_list_created(t_token	*token_list)
{
	if (!token_list)
	{
		ft_printf("create token malloc error!!");
		return (1);
	}
	return (0);
}

static int	is_quotes_opened(t_token	*token_list)
{
	int returnz;
	int quotes_status;

	returnz = 0;
	quotes_status = check_opened_quote(token_list);
	if (quotes_status == STATUS_SQUOTE)
	{
		ft_printf("minishell: line 0: unexpected EOF while looking for matching `''");
		returnz = 1;
	}
	if (quotes_status == STATUS_DQUOTE)
	{
		ft_printf("minishell: line 0: unexpected EOF while looking for matching `\"'");
		returnz = 1;
	}
	if (returnz)
		ft_printf("minishell: line 1: syntax error: unexpected end of file");
	return (returnz);
}

void	parser(t_mini *mini, char *str_line)
{
	t_token	*token_list;

	token_list = lexer_create_tokens(str_line);
	if (is_token_list_created(token_list))
		return ;
	if (is_quotes_opened(token_list))
		return ;
	make_inside_squote_word(token_list);
	make_inside_dquote_word(token_list);
	if (add_empty_string(&token_list))
	{
		printf("kkkk");
		return ;
	}
	remove_invalid_separators(&token_list);
	remove_invalid_expand(&token_list);
	make_invalid_expand_word(&token_list);
	make_expand_after_heredoc_word(&token_list);

	//PENSAR NAS FUNCOES HANDLERs

	if (join_expand_with_word(&token_list))
	{
		//print malloc error
		printf("kkkk");
		return ;
	}
	if(make_expand(&token_list, mini))
	{
		//print malloc error
		printf("kkkk");
		return ;
	}

	if(remove_quotes(&token_list))
	{
		//print malloc error
		printf("kkkk");
		return ;
	}
	if(join_words(&token_list))
	{
		//print malloc error
		printf("kkkk");
		return ;
	}

	REMOVER TODOS OS separator APOS JUNTAR AS PALAVRAS DE VE AJDUAR
	NA HORA DE CRIAR A LISTA DE COMANDOS

	list_token_printf(token_list);

	list_token_clear(&token_list);

	/**
	 * while (lista de tokens)
	 * 		1)juntar $+WORD  em um novo token do tipo expand
	 * 		setar text and text auxilar
	 * 		remover o token $ e WORD e colocar o 1) no lugar
	*/

	/**
	 * while (lista de tokens)
	 * 		fazer o expand token->text + 1 no env_get_value()
	 * 		converter o tipo expand para word
	*/

	//while e juntar palavras DEFAULT_DQUOTE e DEFAULT_SQUOTE '' "" gera pelo menos um string vazia
	//remove "  e  '
	//while juntar todas as palavras => NULL e NULL  = NULL
    //                               => NULL e str   = str
	//                               => str  e NULL   = str
	//nao esquecer obviamente de juntar tmb os text2 por causa do ambiguos no nulll

	//por ultimo apos juntar tudo, podemos remover os separadores
	//isso vai facilitar a gramatica

}