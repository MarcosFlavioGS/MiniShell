/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:58:34 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/20 16:38:45 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/executor/redirect/redirect.h"
#include "../../../include/minishell.h"
#include "../../../libft/libft.h"

t_redirect	*redirect_create(t_token *token_redirect, t_token *token_word)
{
	t_redirect	*new_redirect;
	int			malloc_error;

	malloc_error = 0;
	new_redirect = ft_calloc(1, sizeof(*new_redirect));
	if (!new_redirect)
		return (NULL);
	new_redirect->hdoc_fd = -1;
	new_redirect->type = token_redirect->type;
	if (token_word->text)
	{
		new_redirect->text = ft_strdup(token_word->text);
		malloc_error = (new_redirect->text == NULL);
	}
	if (token_word->text_aux)
	{
		new_redirect->text_aux = ft_strdup(token_word->text_aux);
		malloc_error = (new_redirect->text_aux == NULL);
	}
	if (malloc_error)
	{
		redirect_destroy(new_redirect);
		new_redirect = NULL;
	}
	return (new_redirect);
}

void	redirect_destroy(t_redirect *redirect_free)
{
	if (!redirect_free)
		return ;
	if (redirect_free->text)
		free(redirect_free->text);
	if (redirect_free->text_aux)
		free(redirect_free->text_aux);
	free(redirect_free);
}
