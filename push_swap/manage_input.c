/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:25:06 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/19 09:45:56 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_return_error(void)
{
	printf("%s", "Error\n");
	return (1);
}

int	ft_str_to_int(char *str)
{
	int	count;
	int	sign;
	int	nb;

	count = 0;
	sign = 1;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign *= -1;
		count++;
	}
	nb = 0;
	while (str[count] >= '0' && str[count] <= '9')
	{
		nb = (str[count] - '0') + 10 * nb;
		count++;
	}
	return (nb * sign);
}

int	ft_save_int(char *str, int *i)
{
	*i = 0;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
	while(str[*i])
	{
		if (str[*i] > '9' || str[*i] < '0')
			return (-1);
		(*i)++;
	}
	*i = ft_str_to_int(str);
	return (1);
}