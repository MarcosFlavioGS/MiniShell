/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:53:25 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/28 22:03:09 by mflavio-         ###   ########.fr       */
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

enum Type {word, separator, redir_in, redir_out, append, heredoc, t_pipe};

typedef struct s_token
{
	char			*t_name;
	unsigned int	at_value;
	unsigned int	type;
	unsigned int	expand;
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

typedef struct s_tree
{
	void			*content;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

typedef struct s_mini
{
	t_env		*env_table[ENV_TABLE_SIZE];
	t_tree		*tree;
}	t_mini;

void			lexer(t_mini **mini, char *line, t_tokenstream **tokens);
char			**lexemizer(char *line);
void			expand(t_env *env_table[], t_tokenstream **tokens);
int				operator_handler(char **lexemes, char *line, int i);
unsigned int	hash(const char *str, int size);
void			insert_env_path(t_env *env_table[], char **envp);
char			*get_line(void);
void			execute(t_mini **mini, t_tokenstream **tokens);
void			main_loop(t_mini **mini, char *line, t_tokenstream *tokens);
void			init_tables(t_mini **mini, char **env);
void			free_env_table(t_env **env_table);
// Builtins
int				ft_echo(t_tokenstream **tokens);
int				ft_pwd(void);
void			exit_shell(t_mini **mini, t_tokenstream **tokens);
#endif
