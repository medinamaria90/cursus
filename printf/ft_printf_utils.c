/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:06:29 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/22 17:13:08 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	n;

	if (str == NULL)
		return (ft_putstr("(null)"));
	n = 0;
	while (str[n])
	{
		write(1, &str[n], 1);
		n++;
	}
	return (n);
}

int	ft_putnbr(int n)
{
	int	bytes;

	bytes = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		bytes += 1;
	}
	if (n >= 10)
	{
		bytes += ft_putnbr(n / 10);
	}
	bytes += ft_putchar(n % 10 + '0');
	return (bytes);
}

int	ft_int_to_hex(unsigned long long int num, int mayus, int size)
{
	int	bytes;

	bytes = 0;
	while (num >= 16)
	{
		bytes += ft_int_to_hex(num / 16, mayus, size);
		num = num % 16;
	}
	if (num > 9)
	{
		if (mayus == 0)
			bytes += ft_putchar(num - 10 + 'a');
		if (mayus == 1)
			bytes += ft_putchar(num - 10 + 'A');
	}
	else
		bytes += ft_putchar(num + '0');
	return (bytes);
}

int	ft_putnbr_big(unsigned int n)
{
	int	bytes;

	bytes = 0;
	if (n >= 10)
	{
		bytes += ft_putnbr_big(n / 10);
	}
	bytes += ft_putchar(n % 10 + '0');
	return (bytes);
}
