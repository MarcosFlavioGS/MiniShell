/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_expand2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:12 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 11:26:15 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser/handler_expand.h"
#include "../../include/parser/handler_quotes.h"
#include "../../include/minishell.h"
#include "../../include/parser/list_token.h"
#include "../../include/parser/token.h"
#include "../../libft/libft.h"

/**
 * add_dolar_word - create a new token with the text starting with the $
 * 					caracter
 * @token_word - a word token type.
 *
 * Return:
 *	On success:
 *		a new token
 *	On failure:
 *		NULL (malloc error!)
*/
static t_token	*add_dolar_to_text(t_token *token_word)
{
	char	*new_text;
	t_token	*new_token;

	new_text = ft_strjoin("$", token_word->text);
	if (!new_text)
		return (NULL);
	new_token = token_create(new_text, expand);
	free(new_text);
	return (new_token);
}

/**
 * join_expand_with_word - join the expand tokens with word tokens
 * @token_list:	the token list to join the tokens
 *
 * When the tokens are merged, the new token created has type expand, but with
 * the text of the two tokens.
 *
 * Return:
 *	On success:
 *		0 is returned
 *	On failure:
 *		1 is returned (malloc error!)
*/
int	join_expand_with_word(t_token **token_list)
{
	size_t	count;
	t_token	*token_aux;
	t_token	*token_dolar_with_word;
	t_token	*token_word;

	count = 0;
	token_aux = list_token_get(*token_list, count);
	while (token_aux->type != eol)
	{
		if (token_aux->type == expand && token_aux->next->type == word)
		{
			token_word = list_token_get(*token_list, count + 1);
			token_dolar_with_word = add_dolar_to_text(token_word);
			if (!token_dolar_with_word)
				return (1);
			list_token_add_index(token_list, token_dolar_with_word, count);
			list_token_remove(token_list, count + 1);
			list_token_remove(token_list, count + 1);
		}
		count++;
		token_aux = list_token_get(*token_list, count);
	}
	return (0);
}

/**
 * get_expand_value - convert an expand token into word token by getting a new
 * 					  value for it from env or last_code_exit
 *
 * Return:
 * 	On success:
 * 		0
 * 	On failure:
 * 		1 (malloc error!)
*/
static int	get_expand_value(t_token *expand, const t_mini *mini)
{
	char	*new_text;
	int		env_status;

	env_status = 0;
	if (expand->text[1] == '?')
		new_text = ft_itoa(mini->last_exit_code);
	else
		new_text = env_get_value(mini->env, expand->text + 1, &env_status);
	if (env_status != 0)
		return (1);
	free(expand->text);
	expand->text = new_text;
	expand->type = word;
	return (0);
}

/**
 * make_expand - convert expand token into word tokens by getting values from
 *				 mini pointer
 *
 * Return:
 * 	On success:
 * 		0
 * 	On failure:
 * 		1 (malloc error!)
*/
int	make_expand(t_token **token_list, const t_mini *mini)
{
	t_token	*token_aux;
	char	*value;

	token_aux = list_token_get(*token_list, 0);
	while (token_aux->type != eol)
	{
		if (token_aux->type == expand)
		{
			if (get_expand_value(token_aux, mini))
				return (1);
		}
		token_aux = token_aux->next;
	}
	return (0);
}
