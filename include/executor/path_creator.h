/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_creator.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:17:40 by phz               #+#    #+#             */
/*   Updated: 2023/09/25 15:18:05 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_CREATOR_H
# define PATH_CREATOR_H

int		is_directory(const char *path);

char	*check_path_binary(char *paths[], char *comd, int *malloc_status);

char	*create_full_path(char *path, char *comd);

char	*get_cmd_full_path(char *comd, char **env, int *malloc_status);

#endif