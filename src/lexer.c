#include "../mini_shell.h"

static t_token *new_token(char *content, int type)
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
