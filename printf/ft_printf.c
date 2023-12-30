/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:37:50 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/30 13:16:02 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_0x(uintptr_t num)
{
	if (num == 0)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x"));
}

int	ft_putunbr(unsigned int n)
{
	int	bytes;

	bytes = 0;
	if (n >= 10)
	{
		bytes += ft_putunbr(n / 10);
	}
	bytes += ft_putchar(n % 10 + '0');
	return (bytes);
}

int	take_arg(char c, va_list args)
{
	int			bytes;
	uintptr_t	num;

	bytes = 0;
	if (c == 'c')
		bytes = ft_putchar(va_arg(args, int));
	else if (c == 's')
		bytes = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
	{
		num = va_arg(args, uintptr_t);
		bytes = ft_write_0x(num) + ft_int_to_hex(num, 0, 0);
	}
	else if (c == 'd' || c == 'i')
		bytes = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		bytes = ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'x')
		bytes = ft_int_to_hex(va_arg(args, unsigned int), 0, 1);
	else if (c == 'X')
		bytes = ft_int_to_hex(va_arg(args, unsigned int), 1, 1);
	else if (c == '%')
		bytes = ft_putchar('%');
	return (bytes);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	args;
	int		bytes;

	va_start(args, str);
	i = 0;
	bytes = 0;
	while (str[i])
	{
		if (str[i] != '%')
			bytes += ft_putchar(str[i]);
		if (str[i] == '%')
		{
			bytes += take_arg(str[i + 1], args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (bytes);
}
