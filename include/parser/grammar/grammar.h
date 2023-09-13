/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:47:21 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/13 17:48:14 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAMMAR_H
# define GRAMMAR_H

# include "../../../include/minishell.h"
# include "../../../include/utils/message.h"

//  the grammar methods
void	grammar_word(t_token *token_word, t_grammar *grammar);

void	grammar_pipez(t_token *token_pipez, t_grammar *grammar);

void	grammar_redir_in(t_token *token_redir_in, t_grammar *grammar);

void	grammar_redir_out(t_token *token_redir_out, t_grammar *grammar);

void	grammar_heredoc(t_token *token_redir_heredoc, t_grammar *grammar);

void	grammar_append(t_token *token_redir_append, t_grammar *grammar);

//  other methods
void	print_syntax_err(t_tok_type token_type);

int		check_grammar(t_token *token_list);

#endif