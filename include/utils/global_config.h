/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_config.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 00:46:45 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/25 13:50:59 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_CONFIG_H
# define GLOBAL_CONFIG_H

void	enable_heredoc_config(void);

void	disable_heredoc_config(void);

int		get_heredoc_config(void);

void	enable_redisplay(void);

void	disable_redisplay(void);

#endif