/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_quotes.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:59:39 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/30 17:29:59 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_QUOTES_H
# define HANDLER_QUOTES_H
# include "../../include/minishell.h"

int	get_quote_status(t_tok_type token_type, int status);

int	check_opened_quote(t_token *token_list);

int	add_empty_string(t_token **token_list);

int	remove_quotes(t_token **token_list);

#endif