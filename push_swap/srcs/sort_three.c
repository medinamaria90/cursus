/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:30:01 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/03 21:19:00 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_back(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	min_pos;

	while (*stack_b != NULL)
	{
		pos = find_destination((*stack_b)->content, *stack_a, 'a');
		move_diff_directions(stack_a, pos, count_elements(*stack_a), 'a');
		write(1, "pa\n", 3);
		ft_push(stack_a, stack_b, 1);
	}
	min_pos = ft_find_min(*stack_a, 1);
	move_diff_directions(stack_a, min_pos - 1, count_elements(*stack_a), 'a');
}

void	ft_sort_three(t_stack **stack)
{
	if (is_ordered(*stack) == 0)
		return ;
	else
	{
		if (ft_find_max(*stack, 1) == 2)
		{
			write(1, "rra\n", 4);
			ft_rrotate(stack);
		}
		if (ft_find_max(*stack, 1) == 1)
		{
			write(1, "ra\n", 3);
			ft_rotate(stack);
		}
	}
	if (is_ordered(*stack) == 1)
	{
		write(1, "sa\n", 3);
		ft_swap(stack);
	}
}
