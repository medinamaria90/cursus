/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:37:50 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/09 11:09:51 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_return_bytes(int bytes, int bytes2)
{
	if (bytes2 == -1)
		return (-1);
	return (bytes + bytes2);
}

int	ft_write_0x(uintptr_t num)
{
	if (num == 0)
		return (ft_putstr("0x0"));
	return (ft_putstr("0x"));
}

int	ft_putunbr(unsigned int n)
{
	int	bytes;
	int	written;

	bytes = 0;
	if (n >= 10)
	{
		written = ft_putunbr(n / 10);
		if (written == -1)
			return (-1);
		bytes += written;
	}
	written = ft_putchar(n % 10 + '0');
	if (written == -1)
		return (-1);
	bytes += written;
	return (bytes);
}

int	take_arg(char c, va_list args)
{
	uintptr_t	num;
	int			bytes;

	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
	{
		num = va_arg(args, uintptr_t);
		bytes = ft_write_0x(num);
		if (bytes == -1)
			return (-1);
		return (ft_return_bytes(bytes, ft_int_to_hex(num, 'x', 0)));
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_int_to_hex(va_arg(args, unsigned int), c, 1));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	args;
	int		written;
	int		bytes;

	va_start(args, str);
	i = 0;
	bytes = 0;
	while (str[i])
	{
		if (str[i] != '%')
			written = ft_putchar(str[i]);
		else
		{
			written = take_arg(str[i + 1], args);
			i++;
		}
		if (written == -1)
			return (-1);
		bytes += written;
		i++;
	}
	va_end(args);
	return (bytes);
}
