/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:51 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/05 16:57:19 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser/syntax_list.h"
#include "../../include/minishell.h"
#include "../../include/parser/list_token.h"

/**
 * syntax_list_clear_mini - free the mini's token_list member
*/
void	syntax_list_clear_mini(t_mini *mini)
{
	list_token_clear(&mini->token_list);
	mini->token_list = NULL;
}
