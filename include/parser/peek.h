/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:00:03 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 11:01:14 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEEK_H
# define PEEK_H

# include "../../include/minishell.h"
# include <stddef.h>

t_tok_type	peek(const char *str, size_t index);

#endif
