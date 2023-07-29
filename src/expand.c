/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:34:30 by mflavio-          #+#    #+#             */
/*   Updated: 2023/07/26 20:04:17 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

void	expand(t_env *env_table[], t_tokenstream **tokens)
{
	t_tokenstream	*tmp;

	(void)env_table;
	tmp = *tokens;
	while (tmp)
	{
		if (ft_strnstr(tmp->token->t_name, "$", ft_strlen(tmp->token->t_name))
			&& tmp->token->expand == TRUE)
		{
			printf("expansive: %s\n", tmp->token->t_name);
			//expand_env(&env_table, &tmp);
		}
		tmp = tmp->next;
	}	
}
