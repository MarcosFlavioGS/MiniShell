/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:50:55 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/25 15:47:52 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor/path_creator.h"
#include "../../include/executor/string_array.h"
#include "../../include/minishell.h"
#include "../../include/utils/message.h"
#include <sys/stat.h>

int	is_directory(const char *path)
{
	struct stat	statbuf;

	if (!ft_strchr(path, '/'))
		return (0);
	if (stat(path, &statbuf) == -1)
		return (0);
	if (S_ISDIR(statbuf.st_mode))
	{
		ft_printf(2, "minishell: %s: Is a directory\n", path);
		return (1);
	}
	return (0);
}

static char	*get_path_string(char **env)
{
	char	*env_path;

	env_path = NULL;
	if (!env)
		return (env_path);
	while (*env)
	{
		if (ft_strnstr(*env++, "PATH=", 5))
		{
			env_path = *--env;
			break ;
		}
	}
	return (env_path);
}

char	*create_full_path(char *path, char *comd)
{
	char	*path_full;
	size_t	path_full_size;

	path_full_size = ft_strlen(comd) + ft_strlen(path) + 2;
	path_full = ft_calloc(path_full_size, sizeof(*path_full));
	if (!path_full)
		return (NULL);
	ft_strlcat(path_full, path, path_full_size);
	ft_strlcat(path_full, "/", path_full_size);
	ft_strlcat(path_full, comd, path_full_size);
	return (path_full);
}

char	*check_path_binary(char *paths[], char *comd, int *malloc_status)
{
	char	*full_path_cmd;

	*malloc_status = 0;
	while (*paths)
	{
		full_path_cmd = create_full_path(*paths, comd);
		if (!full_path_cmd)
		{
			*malloc_status = 1;
			break ;
		}
		if (access(full_path_cmd, F_OK | X_OK))
		{
			free(full_path_cmd);
			full_path_cmd = NULL;
		}
		else
			break ;
		paths++;
	}
	return (full_path_cmd);
}

/**
 * get_cmd_fpath - create a full path to the command
 * @comd:			the command string
 * @env:			enviroment
 * @malloc_status:	variable to check possible malloc erros
 *
 * if a string was malloced the caller MUST free the string
 * the caller MUST check the @malloc_status before using return
 *
 * Return:
 * 	On success (malloc_status = 0):
 * 		If the return is NULL, the command was not found.
 *      If not, a string with the absolute path is returned
 *  On failure (malloc_status = 1):
 * 		NULL is retuned
*/
char	*get_cmd_full_path(char *comd, char **env, int *malloc_status)
{
	char	*path_variable;
	char	*cmd_full_path;
	char	**paths;

	path_variable = get_path_string(env);
	cmd_full_path = NULL;
	paths = NULL;
	*malloc_status = 0;
	if (ft_strchr(comd, '/'))
	{
		cmd_full_path = ft_strdup(comd);
		if (!cmd_full_path)
			*malloc_status = 1;
	}
	else if (path_variable)
	{
		paths = ft_split(path_variable, ':');
		if (paths)
			cmd_full_path = check_path_binary(paths, comd, malloc_status);
		else
			*malloc_status = 1;
	}
	if (paths)
		string_array_free(paths);
	return (cmd_full_path);
}
