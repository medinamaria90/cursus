/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:46:14 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/30 13:13:53 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_to_hex(unsigned long long int num, int mayus, int size)
{
	int	bytes;

	bytes = 0;
	if (size == 1)
		num = (unsigned int)num;
	if (size == 0 && num == 0)
		return (0);
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
