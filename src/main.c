/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:52:51 by mflavio-          #+#    #+#             */
/*   Updated: 2023/05/07 01:56:20 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

static void clear_list(t_list_of_tokens *tokens)
{
    t_list_of_tokens *tmp;

    while (tokens)
    {
        tmp = tokens->next;
        free(tokens->token->content);
        free(tokens->token);
        free(tokens);
        tokens = tmp;
    }
}

void ft_echo(t_list_of_tokens **tokens)
{
    t_list_of_tokens *tmp;

    if ((*tokens)->next == NULL)
        return ;
    else
    {
        tmp = (*tokens)->next;
        while (tmp)
        {
            printf("%s", tmp->token->content);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

int main(void)
{
    char                *line;
    t_list_of_tokens    *tokens;

    tokens = NULL;
    while (1)
    {
        line = readline("$> ");
        lexer(line, &tokens);
        free(line);
        if (ft_strncmp(tokens->token->content, "exit", 4) == 0)
            break;
        else if (ft_strncmp(tokens->token->content, "echo", 4) == 0)
            ft_echo(&tokens);
        clear_list(tokens);
        tokens = NULL;
    }
    return (0);
}
