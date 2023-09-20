/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:41:48 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/20 16:41:50 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "../../minishell.h"

t_redirect	*redirect_create(t_token *token_redirect, t_token *token_word);

void		redirect_destroy(t_redirect *free);

#endif