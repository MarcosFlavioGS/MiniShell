/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_expand.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:59:34 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 11:01:55 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_EXPAND_H
# define HANDLER_EXPAND_H

# include "../minishell.h"

void	remove_invalid_expand(t_token **token_list);

void	make_invalid_expand_word(t_token **token_list);

void	make_expand_after_heredoc_word(t_token **token_list);

int		join_expand_with_word(t_token **token_list);

int		make_expand(t_token **token_list, const t_mini *mini);

#endif