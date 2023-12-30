/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:06:29 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/23 12:16:54 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
