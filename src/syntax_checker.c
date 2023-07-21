/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:20:50 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/20 18:09:47 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

bool is_valid_syntax(t_tokenized *tokens)
{}

void syntax_error(t_tokenized **tokens)
{
    if (!is_valid_syntax(*tokens)) {
        fprintf(stderr, "Syntax error: Invalid command\n");
        exit(EXIT_FAILURE);
    }
}