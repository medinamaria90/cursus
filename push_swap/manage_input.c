/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:25:06 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/26 12:04:05 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_return_error(void)
{
	printf("%s", "Error\n");
	return (1);
}


int	ft_save_int(char *str, int *nbr)
{
	int sign;
	int count;

	count = 0;
	sign = 1;
	*nbr = 0;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign *= -1;
		count++;
	}
	while(str[count])
	{
		if (str[count] < '0' || str[count] > '9')
			return (-1);
		if (((2147483647 - (str[count] - '0')) / 10) < *nbr)
		{
            return (-1);
		}
		*nbr = (str[count] - '0') + 10 * (*nbr);
		count++;
	}
	*nbr = (*nbr) * sign;
	return (1);
}

int	ft_process_nbrs(char *input[], t_stack **stack_a)
{
	int n;
	int	nbr;

	n = 0;

	while (input[n])
	{
		if (ft_save_int(input[n], &nbr) == -1)
			return (ft_return_error());
		if (ft_add_node(nbr, stack_a) == -1)
			return (ft_return_error());
		n++;
	}
	return (n);
}

int	are_there_spaces(char *str)
{
	int	n;

	n = 0;
	while(str[n])
	{
		if (str[n] == ' ' || str[n] == '	')
			return (1);
		n++;
	}
	return (0);
}

int	process_input(char *input[], t_stack **stack_a)
{
	int n;
	char **proc_input;
	
	n = 1;
	if (are_there_spaces(input[n]))
	{
		if (input[n + 1])
			return (ft_return_error());
		proc_input = ft_split(input[1], ' ');
		if (proc_input == NULL)
			return (ft_return_error());
		n = ft_process_nbrs(proc_input, stack_a);
	}
	else
		n = ft_process_nbrs(&input[n], stack_a);
	return (n);
}