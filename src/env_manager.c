/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:29:02 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/08/29 14:32:31 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"
#include "../libft/libft.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * env_dup - duplic an array to strings
 * @env:	the string array to duplicate
 *
 * The caller MUST free this return if it was successfull (see env_free method)
 *
 * Return:
 * 	On success:
 * 		a pointer to a new malloced array
 * 	On failure:
 * 		NULL is retorned
 */
char	**env_dup(char **env)
{
	size_t	size_env;
	size_t	count_strings;
	char	**new_env;

	size_env = 0;
	count_strings = 0;
	while (env[size_env])
		size_env++;
	new_env = ft_calloc(size_env + 1, sizeof(*env));
	if (!new_env)
		return (NULL);
	while (count_strings < size_env)
	{
		new_env[count_strings] = ft_strdup(env[count_strings]);
		if (!new_env[count_strings])
		{
			env_free(new_env);
			return (NULL);
		}
		count_strings++;
	}
	return (new_env);
}

/**
 * env_free - free a previously malloced string array
 */
void	env_free(char **env)
{
	size_t	size_env;

	size_env = 0;
	while (env[size_env])
		free(env[size_env++]);
	free(env);
}

/**
 * env_get_value_index - get the index of a variable inside env
 * @env:		the environment string array
 * @variable:	the variable to get the index
 *
 * E.g: env={"a=foo", "b=bar", 0}
 * 	varible "a" return => 0, "b" return => 1, "c" => return => 2
 *
 * Return:
 * 	On success:
 * 		If the variable exist inside env its index is returned
 * 	On failure:
 * 		If the variable DON'T exist inside env index to NULL is returned
 */
size_t	env_get_value_index(char **env, char *variable)
{
	size_t	index;

	index = 0;
	while (env[index])
	{
		if (ft_strnstr(env[index], variable, ft_strlen(variable)))
			return (index);
		index++;
	}
	return (index);
}

/**
 * get_value -	get a variable from environment
 * @env:		the environment string array
 * @variable:	the variable to get the value
 * @status:		checks if there was no error in the execution of the function
 *
 * E.g: env={"a=foo", "b=bar"}, get "b" return a new string => "bar"
 *
 * @status MUST ALWAYS be checked before using the string.
 * if @status != 0 the return is NULL.
 * if @status == 0 and return is != NULL the caller MUST ALWAYS free the string.
 *
 * Return:
 *	On success (status == 0):
 *		a new string if the variable was found in the env (string can be empty)
 *		NULL if the variable wasn't found.
 *	On failure (status != 0):
 *		return always will be NULL
 *		status == ENV_INVLD_PARAM: the env or variable == NULL or variable is
 								   a empty string
 *		status == ENV_MALLOC_ERROR: the malloc to the new string failed.
 */
char	*env_get_value(char **env, char *variable, int *status)
{
	char	*value;
	char	*variable_and_value;
	size_t	variable_index;

	*status = 0;
	if (!env || !variable || !ft_strlen(variable))
	{
		*status = ENV_INVLD_PARAM;
		return (NULL);
	}
	variable_index = env_get_value_index(env, variable);
	variable_and_value = env[variable_index];
	if (variable_and_value)
	{
		value = ft_substr(variable_and_value, ft_strlen(variable) + 1,
				ft_strlen(variable_and_value));
		if (!value)
		{
			*status = ENV_MALLOC_ERROR;
			return (NULL);
		}
		return (value);
	}
	return (NULL);
}
