/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:28:43 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/08/30 23:32:32 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/libft.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * env_add_value2 - add a new variable to an new env
 * @old_env:	the actual env string array
 * @v_and_v:	the new variable to add a env (variable=value)
 *
 * Return:
 * 	On success:
 * 		a new env is returned and old_env is freed
 * 	On failure:
 *		NULL is returned old_env is not changed
 */
static char	**env_add_value2(char **old_env, char *v_and_v)
{
	size_t	size_env;
	size_t	count_strings;
	char	**new_env;
	char	*new_variable;

	size_env = 0;
	count_strings = 0;
	while (old_env[size_env])
		size_env++;
	new_variable = ft_strdup(v_and_v);
	new_env = ft_calloc(size_env + 2, sizeof(*old_env));
	if (!new_env || !new_variable)
		return (NULL);
	while (count_strings < size_env)
	{
		new_env[count_strings] = old_env[count_strings];
		count_strings++;
	}
	new_env[count_strings] = new_variable;
	free(old_env);
	return (new_env);
}

/**
 * env_set_value - replaces a variable within the array of string
 * @env: 			string array
 * @v_and_v:		new variable to replace (variable=value)
 * @index_value:	index to replace the new variable
 *
 * Return:
 *	 On success:
 *		return 0 and the old variable is freed
 *	 On failure:
 *		return ENV_MALLOC_ERROR and the variable don't change
 */
static int	env_set_value(char **env, char *v_and_v, size_t index_value)
{
	char	*new_variable;

	new_variable = ft_strdup(v_and_v);
	if (!new_variable)
		return (ENV_MALLOC_ERROR);
	free(env[index_value]);
	env[index_value] = new_variable;
	return (0);
}

/**
 * env_copy -	copies the strings from one array (old) to another (new) and
 * 				skips 1 string (jump) from (old)
 * @o_env:		copy from
 * @n_env:		copy to
 * @old_size:	the o_env size
 * @jump:		index of the string to be skipped
 */
static void	env_copy(char **o_env, char**n_env, size_t old_size, size_t jump)
{
	size_t	count_strings_new;
	size_t	count_strings_old;

	count_strings_new = 0;
	count_strings_old = 0;
	old_size--;
	while (count_strings_new < old_size)
	{
		if (count_strings_new == jump)
			count_strings_old++;
		n_env[count_strings_new] = o_env[count_strings_old];
		count_strings_new++;
		count_strings_old++;
	}
}

/**
 * env_add_value - add a new variable value pair to the env
 * @env:		a pointer to the string array
 * @v_and_v:	new variable value pair (variable=value) to add
 *
 * If the variable exists, it is replaced.
 *
 * Return:
 * 	 On success:
 * 		0 is returned
 *   On failure (the variable isn't added):
 * 		ENV_INVLD_PARAM => the v_and_v isn't a valid string
 * 		ENV_MALLOC_ERROR => malloc error
 */
int	env_add_value(char ***env, char *v_and_v)
{
	char	**new_env;
	size_t	variable_index;
	char	*variable;

	variable_index = 0;
	if (!ft_strlen(v_and_v) || !ft_strchr(v_and_v, '=')
		|| ft_strchr(v_and_v, '=') == v_and_v)
		return (ENV_INVLD_PARAM);
	variable = ft_substr(v_and_v, 0, (ft_strchr(v_and_v, '=') - v_and_v));
	if (!variable)
		return (ENV_MALLOC_ERROR);
	variable_index = env_get_value_index(*env, variable);
	free(variable);
	if ((*env)[variable_index])
		env_set_value(*env, v_and_v, variable_index);
	else
	{
		new_env = env_add_value2(*env, v_and_v);
		if (!new_env)
			return (ENV_MALLOC_ERROR);
		*env = new_env;
	}
	return (0);
}

/**
 * env_remove_value - remove a variable value pair to the env
 * @env:		a pointer to the string array
 * @variable: 	variable to remove, example: PATH
 *
 * Return:
 * 	 On success:
 * 		0 is returned
 * 	 On failure (the variable isn't removed):
 * 		ENV_MALLOC_ERROR => could not create a new array of strings
 */
int	env_remove_value(char ***env, char *variable)
{
	char	**new_env;
	size_t	old_env_size;
	size_t	variable_index;

	variable_index = env_get_value_index(*env, variable);
	if (!(*env)[variable_index])
		return (0);
	old_env_size = 0;
	while ((*env)[old_env_size])
		old_env_size++;
	new_env = ft_calloc(old_env_size, sizeof(*new_env));
	if (!new_env)
		return (ENV_MALLOC_ERROR);
	env_copy(*env, new_env, old_env_size, variable_index);
	free((*env)[variable_index]);
	free(*env);
	*env = new_env;
	return (0);
}
