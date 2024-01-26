/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:19:44 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/26 11:40:41 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	best_movement(int *pos_a, int pos_b, int len_a, int len_b)
{
	int	cost_rr;
	int	cost_rrr;
	int cost_sep_ways;
	
	cost_rr = (*pos_a > pos_b) ? *pos_a : pos_b;	
	cost_rrr = ((len_a - *pos_a > len_b - pos_b) ? len_a - *pos_a : len_b - pos_b);
	cost_sep_ways = (*pos_a > len_a / 2 ? len_a - *pos_a : *pos_a);
	cost_sep_ways += (pos_b > len_b / 2 ? len_b - pos_b : pos_b);
	if (cost_rr <= cost_rrr && cost_rr <= cost_sep_ways)
	{
		*pos_a = ++cost_rr;
		return (1);
	}
	else if (cost_rrr <= cost_rr && cost_rrr <= cost_sep_ways)
	{
		*pos_a = ++cost_rrr;
		return (2);
	}
	*pos_a = ++cost_sep_ways;
	return (3);
}

int calculate_cost(t_stack *stack_a, t_stack *stack_b, int pos_a, int a_value)
{
	int	len_b;
	int	len_a;

	len_b = count_elements(stack_b);
	len_a = count_elements(stack_a);
	while (stack_a->content != a_value)
		stack_a = stack_a->next;
	stack_a->place_to_go = find_destination(a_value, stack_b, 'b');
	stack_a->movement = best_movement(&pos_a, stack_a->place_to_go , len_a, len_b);
	stack_a->cost = (pos_a);
	return (stack_a->cost);
}

int	count_elements(t_stack *stack)
{
	int		count;

	count = 0;
	while(stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return(count);
}


int	find_cheapest_movement(t_stack *stack_a, t_stack *stack_b)
{
	int	cost;
	int	min_cost;
	int	min_cost_position;
	int	pos_a;
	t_stack	*temp;

	min_cost = INT_MAX;
	pos_a = 0;
	temp = stack_a;
	while (temp != NULL)
	{
		cost = calculate_cost(stack_a, stack_b, pos_a, temp->content);
		if (cost < min_cost)
		{
			min_cost = cost;
			min_cost_position = pos_a;
		}
		temp = temp->next;
		pos_a++;
	}
	return (min_cost_position);
}
