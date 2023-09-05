/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:00:10 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 11:04:52 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include "../minishell.h"
# include <stddef.h>

t_token	*hdl_one_char(t_stream *tok, const char *text, t_tok_type type);

t_token	*hdl_many_char(t_stream *stream, t_tok_type type);

t_token	*token_create(const char *text, t_tok_type type);

void	token_destroy(t_token *token_free);

//the tokens types
t_token	*token_separator(t_stream *stream);

t_token	*token_redir_in(t_stream *stream);

t_token	*token_redir_out(t_stream *stream);

t_token	*token_pipe(t_stream *stream);

t_token	*token_expand(t_stream *stream);

t_token	*token_eol(t_stream *stream);

t_token	*token_dquote(t_stream *stream);

t_token	*token_squote(t_stream *stream);

t_token	*token_word(t_stream *stream);

t_token	*token_equal(t_stream *stream);

t_token	*token_interrogation(t_stream *stream);

#endif
