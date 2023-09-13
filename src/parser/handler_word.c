/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:32 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 11:38:45 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser/handler_word.h"
#include "../../include/minishell.h"
#include "../../include/parser/list_token.h"
#include "../../include/parser/token.h"

/**
 * join_strings - join 2 strings whether they are null or not.
 * @text1: 			the string 1 to join
 * @text2: 			the string 2 to join
 * @malloc_status:	a pointer to an integer to check if there were any malloc
 * 					error (the value of this pointer will always be changed by
 * 					the function, in case you need it before calling the
 * 					function save it in another variable.)
 *
 * @malloc_status MUST ALWAYS be checked before using the string. If it is != 0
 * there was a malloc error and the return MUST NOT be used.
 *
 * NULL + NULL  = NULL
 * NULL + str2  = new str2
 * str1 + NULL  = new str1
 * str1 + str2  = new str3
 *
 * Return:
 * 	On sucess (malloc_status = 0):
 * 		NULL if text1 and text2 are NULL, or a new string
 *  On failure (malloc_statu = 1)
 * 		Return is undefined
*/
static char	*join_strings(char *text1, char *text2, int *malloc_status)
{
	char	*new_text;

	new_text = NULL;
	*malloc_status = 0;
	if (text1 && text2 == NULL)
	{
		new_text = ft_strdup(text1);
		if (!new_text)
			*malloc_status = 1;
	}
	else if (text1 == NULL && text2)
	{
		new_text = ft_strdup(text2);
		if (!new_text)
			*malloc_status = 1;
	}
	else if (text1 && text2)
	{
		new_text = ft_strjoin(text1, text2);
		if (!new_text)
			*malloc_status = 1;
	}
	return (new_text);
}

/**
 * join_word_token - create a new word token joining the texts from token_word1
 * 					 and token_word2
 * @token_word1:	the token 1 to join
 * @token_word2:	the token 2 to join
 *
 * Return:
 * 	On success:
 * 		a new word token
 *  On failure:
 * 		NULL (malloc error!)
*/
static t_token	*join_word_token(t_token *token_word1, t_token *token_word2)
{
	t_token	*new_token;
	char	*new_text;
	char	*new_text_aux;
	int		malloc_status;

	new_text = NULL;
	new_text_aux = NULL;
	malloc_status = 0;
	new_text = join_strings(token_word1->text,
			token_word2->text, &malloc_status);
	if (malloc_status)
		return (NULL);
	new_text_aux = join_strings(token_word1->text_aux,
			token_word2->text_aux, &malloc_status);
	if (malloc_status)
		return (NULL);
	new_token = token_create(NULL, word);
	if (!new_token)
		return (NULL);
	new_token->text = new_text;
	new_token->text_aux = new_text_aux;
	return (new_token);
}

/**
 * join_words - joins all word type tokens that are not separated by another
 * 				type of token.
 *
 * Return:
 * 	On success:
 * 		0
 *  On failure:
 * 		1 (malloc error!)
*/
int	join_words(t_token **token_list)
{
	t_token	*token_word;
	t_token	*new_token_word;
	size_t	count;

	count = 0;
	token_word = list_token_get(*token_list, count);
	while (token_word->type != eol)
	{
		if (token_word->type == word && token_word->next->type == word)
		{
			new_token_word = join_word_token(token_word, token_word->next);
			if (!new_token_word)
				return (1);
			list_token_add_index(token_list, new_token_word, count);
			list_token_remove(token_list, count + 1);
			list_token_remove(token_list, count + 1);
		}
		else
			count++;
		token_word = list_token_get(*token_list, count);
	}
	return (0);
}
