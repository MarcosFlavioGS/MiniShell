/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 03:29:17 by mflavio-          #+#    #+#             */
/*   Updated: 2022/10/21 03:29:27 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swapp(char *str)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (j > i)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

static int	hex_convert(unsigned long c, int ascii)
{
	int		remainder;
	int		i;
	char	*ret;

	i = 0;
	if (!c)
		return (i += ft_putchar_fd('0', 1));
	ret = malloc(ft_numlen(c) + 1);
	remainder = 0;
	while (c != 0)
	{
		remainder = c % 16;
		if (remainder < 10)
			ret[i++] = remainder + 48;
		else
			ret[i++] = remainder + ascii;
		c /= 16;
	}
	ret[i] = '\0';
	ft_swapp(ret);
	i = ft_putstr_fd(ret, 1);
	free(ret);
	return (i);
}

static int	ft_ptr(unsigned long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i += ft_putstr_fd(OSNULL, 1);
	else
	{
		i += ft_putstr_fd("0x", 1);
		i += hex_convert(n, 87);
	}
	return (i);
}

static int	checker(char const c, va_list ap)
{
	int	len;

	len = 0;
	if (c == '%')
		len += ft_putchar_fd('%', 1);
	else if (c == 'c')
		len += ft_putchar_fd((char) va_arg(ap, int), 1);
	else if (c == 's')
		len += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (c == 'p')
		len += ft_ptr(va_arg(ap, unsigned long int));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'u')
		len += ft_putnbr_fd(va_arg(ap, unsigned int), 1);
	else if (c == 'X')
		len += hex_convert(va_arg(ap, unsigned int), 55);
	else if (c == 'x')
		len += hex_convert(va_arg(ap, unsigned int), 87);
	return (len);
}

int	ft_printf(const char *placeholders, ...)
{
	va_list	ap;
	int		len;

	if (!placeholders)
		return (-1);
	len = 0;
	va_start(ap, placeholders);
	while (*placeholders)
	{
		if (*placeholders == '%')
		{
			placeholders++;
			len += checker(*placeholders, ap);
		}
		else
			len += ft_putchar_fd(*placeholders, 1);
		placeholders++;
	}
	va_end(ap);
	return (len);
}
