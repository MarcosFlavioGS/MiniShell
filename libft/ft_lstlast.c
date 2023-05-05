/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:12:55 by mflavio-          #+#    #+#             */
/*   Updated: 2022/09/27 00:13:01 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*l_cpy;

	l_cpy = lst;
	if (!l_cpy)
		return (NULL);
	while (l_cpy->next)
	{
		l_cpy = l_cpy->next;
	}
	return (l_cpy);
}
