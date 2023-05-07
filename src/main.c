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

t_token *new_token(char *content, int type)
{
    t_token *token;

    token = malloc(sizeof(t_token));
    token->content = malloc(ft_strlen(content) + 1);
    ft_strlcpy(token->content, content, ft_strlen(content) + 1);
    token->type = type;
    token->content[ft_strlen(content)] = '\0';
    return (token);
}

void lexer(char *line, t_list_of_tokens **tokens)
{
    t_token             *token;
    t_list_of_tokens    *current;
    char                **token_array;
    int                 i;

    i = 0;
    token_array = ft_split(line, ' ');
    current = *tokens;
    while (token_array[i])
    {
        token = new_token(token_array[i], 0);
        if (!current)
        {
            *tokens = malloc(sizeof(t_list_of_tokens));
            (*tokens)->token = token;
            (*tokens)->next = NULL;
            current = *tokens;
        }
        else
        {
            current->next = malloc(sizeof(t_list_of_tokens));
            current->next->token = token;
            current->next->next = NULL;
            current = current->next;
        }
        i++;
    }
    i = 0;
    while (token_array[i])
    {
        free(token_array[i]);
        i++;
    }
    free(token_array);
}

void print_list(t_list_of_tokens **tokens)
{
    t_list_of_tokens *tmp;

    tmp = *tokens;
    while (tmp)
    {
        printf("content: %s\n", tmp->token->content);
        printf("type: %d\n", tmp->token->type);
        tmp = tmp->next;
    }
}

void clear_list(t_list_of_tokens *tokens)
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
        //print_list(&tokens);
        if (ft_strncmp(tokens->token->content, "exit", 4) == 0)
            break;
        else if (ft_strncmp(tokens->token->content, "echo", 4) == 0)
            printf("%s\n", tokens->next->token->content);
        clear_list(tokens);
        tokens = NULL;
    }
    return (0);
}
