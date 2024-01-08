/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:06:29 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/08 19:12:57 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	bytes;
	int	written;

	bytes = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		written = ft_putchar('-');
		if (written == -1)
			return (-1);
		n = -n;
		bytes += written;
	}
	if (n >= 10)
	{
		written = ft_putnbr(n / 10);
		if (written == -1)
			return (-1);
		bytes += written;
	}
	written = ft_putchar(n % 10 + '0');
	if (written == -1)
		return (-1);
	return (bytes + written);
}
