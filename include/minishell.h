/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:53:25 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/05 16:09:02 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <string.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stddef.h>

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

# define STATUS_DEFAULT 0
# define STATUS_DQUOTE 1
# define STATUS_SQUOTE 2

typedef enum e_tok_type
{
	word=1,
	separator,
	redir_in,
	redir_out,
	append,
	heredoc,
	pipez,
	expand,
	dquote,
	squote,
	equal,
	interrogation,
	eol
}	t_tok_type;

typedef struct s_token	t_token;
typedef struct s_token
{
	char		*text;
	char		*text_aux;
	t_tok_type	type;
	t_token		*next;
}	t_token;

typedef struct s_stream
{
	const char	*line;
	size_t		index;
}t_stream;

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
	t_token	*token_list;
	int		last_exit_code;
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
