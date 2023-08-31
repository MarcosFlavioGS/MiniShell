/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:53:25 by mflavio-          #+#    #+#             */
/*   Updated: 2023/08/31 17:40:09 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <string.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define ENV_TABLE_SIZE 100
# define TRUE 1
# define FALSE 0
# define S_QUOTE 39
# define D_QUOTE 34
# define PIPE 124
# define REDIR_IN 60
# define REDIR_OUT 62

# define ENV_INVLD_PARAM 1
# define ENV_MALLOC_ERROR 2

enum e_type {word, separator, redir_in, redir_out, append, heredoc, t_pipe};

enum e_quote {noquote, squote, dquote};

typedef struct s_token
{
	char			*t_name;
	unsigned int	at_value;
	enum e_type		type;
	enum e_quote	quote;
}	t_token;

typedef struct s_tokenstream
{
	t_token					*token;
	struct s_tokenstream	*next;
}	t_tokenstream;

typedef struct s_env
{
	char			*name;
	char			*path;
	struct s_env	*next;
}	t_env;

typedef struct s_mini
{
	char	**env;
}	t_mini;

void			lexer(char *line, t_tokenstream **tokens);
char			**lexemizer(char *line);
int				operator_handler(char **lexemes, char *line, int i);
int				special_strlen(char *line);
unsigned int	hash(const char *str, int size);
void			insert_env_path(t_env *env_table[], char **envp);
char			*get_line(void);
void			execute(t_mini **mini, t_tokenstream **tokens);
void			main_loop(t_mini **mini, char *line, t_tokenstream *tokens);
void			free_env_table(t_env **env_table);
void			free_array(char **array);
// Builtins
int				ft_echo(t_tokenstream **tokens);
int				ft_pwd(void);
void			exit_shell(t_mini **mini, t_tokenstream **tokens);

//env_manager.c
char			**env_dup(char **env);
void			env_free(char **env);
size_t			env_get_value_index(char **env, char *variable);
char			*env_get_value(char **env, char *variable, int *status);
int				env_add_value(char ***env, char *v_and_v);
int				env_remove_value(char ***env, char *variable);

//minishell_manager.c
t_mini			*mini_create(char **env);
void			mini_destroy(t_mini *mini);

#endif
