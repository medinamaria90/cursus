/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:48:03 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/11 11:42:10 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_write_zero(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*ft_write_smallest(void)
{
	char	*str;

	str = ft_strdup("-2147483648");
	if (str == NULL)
		return (NULL);
	return (str);
}

static int	ft_num_digits(int n)
{
	int	digits;

	digits = 1;
	if (n < 0)
	{
		digits++;
		n = -n;
	}
	while (n >= 10)
	{
		digits++;
		n = n / 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;

	if (n == -2147483648)
		return (ft_write_smallest());
	if (n == 0)
		return (ft_write_zero());
	digits = ft_num_digits(n);
	str = (char *)malloc(sizeof(char) * digits + 1);
	if (str == NULL)
		return (NULL);
	str[digits--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[digits--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char *res = ft_itoa(-2147483648);
	printf("%s\n", res);
	free(res);	
}
*/