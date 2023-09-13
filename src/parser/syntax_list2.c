/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:51 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/09/13 11:45:26 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor/executor_utils.h"
#include "../../include/parser/syntax_list.h"
#include "../../include/minishell.h"
#include "../../include/parser/list_token.h"

/**
 * syntax_list_clear_mini - free the mini's token_list member
*/
void	syntax_list_clear_mini(t_mini *mini)
{
	if (!mini)
		return ;
	if (mini->token_list)
	{
		list_token_clear(&mini->token_list);
		mini->token_list = NULL;
	}
	if (mini->command_list)
	{
		command_list_destroy(mini->command_list);
		mini->command_list;
	}
}
