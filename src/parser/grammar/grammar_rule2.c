/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_rule2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:36:50 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/13 17:36:50 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
#include "../../../include/parser/grammar/grammar.h"

void	grammar_append(t_token *token_redir_append, t_grammar *grammar)
{
	if (token_redir_append->next->type != word)
	{
		print_syntax_err(token_redir_append->next->type);
		grammar->is_grammar_err = 1;
	}
	grammar->count += 2;
}
