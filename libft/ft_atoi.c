/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:01:48 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/01 12:53:30 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	count;
	int	sign;
	int	nb;

	count = 0;
	sign = 1;
	while (str[count] == ' ' || str[count] == '\f' || str[count] == '\n'
		|| str[count] == '\r' || str[count] == '\t' || str[count] == '\v')
		count++;
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
