/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:53:25 by mflavio-          #+#    #+#             */
/*   Updated: 2023/04/20 18:53:49 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H
# include "libft/libft.h"
# include <string.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_token
{
	char			*t_name;
	unsigned int	at_value;
}	t_token;

typedef struct s_symbols
{
	char	*name;
	int		at_value;
}	t_symbols;

typedef struct s_hash_table
{
	t_symbols	**items;
}	t_hashTable;

typedef struct s_tokenized
{
	t_token				*token;
	struct s_tokenized	*next;
}	t_tokenized;

void			lexer(char *line, t_tokenized **tokens);
char			**lexemizer(char *line);
unsigned int	hash(const char *str);
#endif
