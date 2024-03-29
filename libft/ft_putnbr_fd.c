/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:16:53 by mflavio-          #+#    #+#             */
/*   Updated: 2023/09/22 21:13:07 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(long n, int fd)
{
	char	num;
	int		len;

	num = 0;
	len = 0;
	if (n >= 10)
	{
		num = n % 10 + '0';
		n /= 10;
		len += ft_putnbr_fd(n, fd);
		len += write(fd, &num, 1);
	}
	else if (0 <= n && n <= 9)
	{
		n += '0';
		len += write(fd, &n, 1);
	}
	else if (n < 0)
	{
		n *= (-1);
		len += write(1, "-", 1);
		len += ft_putnbr_fd(n, fd);
	}
	return (len);
}
