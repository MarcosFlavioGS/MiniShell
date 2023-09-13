/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:48:36 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/13 17:48:37 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_ARRAY_H
# define STRING_ARRAY_H
# include <stddef.h>

void	string_array_free(char **env);

char	**string_array_create(size_t amount_of_strings);

int		string_array_add(char ***str_arr, char *new_string);

#endif