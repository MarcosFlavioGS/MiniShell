/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:53:25 by mflavio-          #+#    #+#             */
/*   Updated: 2023/08/02 16:35:39 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H
# include "libft/libft.h"
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

enum e_type {word, separator, redir_in, redir_out, append, heredoc, t_pipe};

enum e_quote {noquote, squote, dquote};

typedef struct s_token
{
	char			*t_name;
	unsigned int	at_value;
	enum e_type		type;
	enum e_quote	quote;
}	t_token;

typedef struct t_tokenstream
{
	t_token					*token;
	struct t_tokenstream	*next;
}	t_tokenstream;

typedef struct s_env
{
	char			*name;
	char			*path;
	struct s_env	*next;
}	t_env;

typedef struct s_mini
{
	t_env	*env_table[ENV_TABLE_SIZE];
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
void			init_tables(t_mini **mini, char **env);
void			free_env_table(t_env **env_table);
void			free_array(char **array);
// Builtins
int				ft_echo(t_tokenstream **tokens);
int				ft_pwd(void);
void			exit_shell(t_mini **mini, t_tokenstream **tokens);
#endif
