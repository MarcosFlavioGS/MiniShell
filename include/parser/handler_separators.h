/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_separators.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:59:43 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 11:02:15 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_SEPARATORS_H
# define HANDLER_SEPARATORS_H

# include "../../include/minishell.h"

void	remove_invalid_separators(t_token **token_list);

int		remove_separators(t_token **token_list);

#endif
