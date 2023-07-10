/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:43:37 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/10 01:00:42 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"



static int check_for_operators(char *t_name)
{
    if (ft_strnstr(t_name, ">", ft_strlen(t_name)) != NULL)
        return (TRUE);
    else if (ft_strnstr(t_name, "<", ft_strlen(t_name)) != NULL)
        return (TRUE);
    else if (ft_strnstr(t_name, ">>", ft_strlen(t_name)) != NULL)
        return (TRUE);
    else if (ft_strnstr(t_name, "<<", ft_strlen(t_name)) != NULL)
        return (TRUE);
    else if (ft_strnstr(t_name, "|", ft_strlen(t_name)) != NULL)
        return (TRUE);
    else
        return (FALSE);
}

static void separate_tokens(t_tokenized *head)
{
    t_tokenized *new_tokenized;
    t_token *token;
    char **new_lexemes;

    new_lexemes = special_split_with_operators(head->token->t_name);
}

void separate_operators(t_tokenized **tokens)
{
    t_tokenized *tmp;

    tmp = *tokens;
    while (tmp)
    {
        if (tmp->token->t_name[0] == S_QUOTE || tmp->token->t_name[0] == D_QUOTE)
            tmp = tmp->next;
        else
        {
            if (check_for_operators(tmp->token->t_name) == TRUE)
                separate_tokens(tmp);
        }
  }
}
