/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:42:03 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/13 17:42:37 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../../libft/libft.h"

/**
 * get_str_array_size - returns the number of strings in the array of strings
 *
 * Return:
 * 	 The number of strings in the array of strings
*/
static size_t	get_str_array_size(char **str_arr)
{
	size_t	count;

	count = 0;
	while (str_arr[count])
		count++;
	return (count);
}

/**
 * string_array_free - free a previously malloced string array
 */
void	string_array_free(char **env)
{
	size_t	size_env;

	size_env = 0;
	while (env[size_env])
		free(env[size_env++]);
	free(env);
}

/**
 * string_array_create - create a new string array, NULL is automatically added
 * 						 to the end of the array.
 * @amount_of_strings:	number of strings in this array not counting NULL
 *
 * Return:
 * 	On success:
 * 		a pointer to the empty string array
 *	On failure:
 *		NULL
*/
char	**string_array_create(size_t amount_of_strings)
{
	char	**new_argv;

	new_argv = ft_calloc(amount_of_strings + 1, sizeof(*new_argv));
	return (new_argv);
}

/**
 * string_array_add - add a string the string array
 *
 * @str_arr:	pointer to the string array (if NULL a new string array is
 * 				created)
 * @new_string:	the string to add in the array
 *
 * Return:
 * 	On success:
 * 		0 is returned the @str_arr points to a new pointer
 *  On failure (malloc error!):
 * 		1 is returned and @str_arr don't change
*/
int	string_array_add(char ***str_arr, char *new_string)
{
	char	**new_str_arr;
	char	**act_str_arr;
	size_t	new_str_arr_size;
	size_t	count_elements;

	act_str_arr = *str_arr;
	if (!act_str_arr)
		act_str_arr = string_array_create(0);
	if (!act_str_arr)
		return (1);
	new_str_arr_size = get_str_array_size(act_str_arr) + 1;
	new_str_arr = string_array_create(new_str_arr_size);
	if (!new_str_arr)
		return (1);
	count_elements = 0;
	while (act_str_arr[count_elements])
	{
		new_str_arr[count_elements] = act_str_arr[count_elements];
		count_elements++;
	}
	new_str_arr[count_elements] = new_string;
	*str_arr = new_str_arr;
	free(act_str_arr);
	return (0);
}
