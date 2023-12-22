/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:27:50 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/21 19:05:10 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
int ft_int_to_hex(long int num) 
{
	int	bytes;
	
	bytes = 0;
	while (num >= 16)
	{
		bytes += ft_int_to_hex(num / 16);
		num = num % 16;
	}
	if (num > 9)
		bytes += ft_putchar(num - 10 + 'a');
	else
		bytes += ft_putchar(num + '0');
	return (bytes);
}

int	ft_putptr(void *ptr)
{
	int bytes;
	
	bytes = ft_putstr("0x");
	bytes += ft_int_to_hex((uintptr_t)ptr);
	return (bytes);
}
int ft_putfloat(float n)
{
	float dec;

	dec = (n - (n / 10)) * 10;
	while (dec > 0)
		
	
}