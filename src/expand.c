/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:34:30 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/26 18:16:42 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

void    expand(t_env *env_table[],t_tokenized **tokens)
{
    printf("expand: %s, %s\n", (*tokens)->token->t_name, env_table[15]->name);
}