/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:30:01 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/19 09:45:46 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_stack(t_stack **stack)
{
	int min_pos;

	min_pos = ft_find_min(*stack, 1);
	ft_best_movement(stack, min_pos - 1, ft_count_elements(*stack), 'a');
}

void	ft_push_back(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	//ft_print_stack(*stack_a, 'A');
	//ft_print_stack(*stack_b, 'B');
	while (*stack_b != NULL)
	{
		pos = ft_find_pos((*stack_b)->content, *stack_a, 'a');
		//printf("Pos of %d is %d\n", (*stack_b)->content, pos);
		ft_best_movement(stack_a, pos, ft_count_elements(*stack_a), 'a');
		printf("pb\n");
		ft_push(stack_a, stack_b, 1);
		//ft_print_stack(*stack_a, 'A');
	}
	ft_order_stack(stack_a);
}

void	ft_sort_three(t_stack **stack)
{
	//printf("going to order\n");
	if (ft_is_ordered(*stack) == 0)
		return ;
	else
	{
		if(ft_find_max(*stack, 1) == 2)
		{
			printf("rra\n");
			ft_rotate(stack);
			//ft_print_stack(*stack, 'A');
		}
		if(ft_find_max(*stack, 1) == 1)
		{
			printf("ra\n");
			ft_rrotate(stack);
			//ft_print_stack(*stack, 'A');
		}
	}
	if (ft_is_ordered(*stack) == 1)
	{
		printf("sa\n");
		ft_swap(stack);
		//ft_print_stack(*stack, 'A');
	}
	//printf("Here the result\n");
	//ft_print_stack(*stack, 'A');
}