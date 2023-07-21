/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:03:02 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/20 20:57:46 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

void	parser(t_mini *mini, t_tokenized **tokens)
{
	// 1. Check for syntax errors
	// 2. Create the tree
	mini->tree = NULL;
	syntax_error(tokens);
	mini->tree = create_tree(tokens);
}
