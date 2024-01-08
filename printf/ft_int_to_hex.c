/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:46:14 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/08 19:12:26 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_to_hex(unsigned long long int num, char type, int size)
{
	int	bytes;
	int	written;

	bytes = 0;
	if (size == 1)
		num = (unsigned int)num;
	if (size == 0 && num == 0)
		return (0);
	while (num >= 16)
	{
		written = ft_int_to_hex(num / 16, type, size);
		if (written == -1)
			return (-1);
		bytes += written;
		num = num % 16;
	}
	if (num > 9)
		written = ft_putchar(num - 10 + type - ('x' - 'a'));
	else
		written = ft_putchar(num + '0');
	if (written == -1)
		return (-1);
	bytes += written;
	return (bytes);
}
