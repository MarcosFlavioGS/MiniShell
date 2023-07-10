/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:53:25 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/05 19:44:21 by mflavio-         ###   ########.fr       */
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
# define SYMBOL_TABLE_SIZE 15
# define TRUE 1
# define FALSE 0
# define S_QUOTE 34
# define D_QUOTE 39

typedef struct s_token
{
	char			*t_name;
	unsigned int	at_value;
}	t_token;

typedef struct s_tokenized
{
	t_token				*token;
	struct s_tokenized	*next;
}	t_tokenized;

typedef struct s_symbols
{
	char				*name;
	char				*type;
	int					at_value;
	struct s_symbols	*next;
}	t_symbols;

typedef struct s_env
{
	char			*name;
	char			*path;
	char			*at_value;
	struct s_env	*next;
}	t_env;

typedef struct s_mini
{
	t_symbols	**symbol_table;
	t_env		**env_table;
}	t_mini;

void			lexer(char *line, t_tokenized **tokens);
void			separate_operators(t_tokenized **tokens);
char			**lexemizer(char *line);
unsigned int	hash(const char *str);
unsigned int	hash_env(const char *str);
void			insert_builtins(t_symbols *symbol_table[]);
void			insert_operators(t_symbols *symbol_table[]);
void			insert_env_path(t_env *env_table[], char **envp);
void			insert(t_symbols *table[], t_symbols *symbol);
char			*get_line(void);
void			execute(t_tokenized **tokens);
void			main_loop(char *line, t_tokenized *tokens);
void			init_tables(t_mini *mini, char **env);
// Builtins
int				ft_echo(t_tokenized **tokens);
int				ft_pwd(void);
#endif
