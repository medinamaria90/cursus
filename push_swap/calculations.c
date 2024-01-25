/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:19:44 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/25 21:15:14 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int ft_cost_element(t_stack *a, t_stack *b, int pos_a, int a_value)
{
	int	len_b;
	int	len_a;
	int	pos_b;

	len_b = ft_count_elements(b);
	len_a = ft_count_elements(a);
	pos_b = ft_find_pos(a_value, b, 'b');
	while (a->content != a_value)
		a = a->next;
	a->cost = (pos_a > pos_b) ? pos_a : pos_b;
	a->movement = 1;
	a->place_to_go = pos_b;
	if (((len_a - pos_a > len_b - pos_b) ? len_a - pos_a : len_b - pos_b) < (a->cost))
		{
			a->cost = (len_a - pos_a > len_b - pos_b) ? len_a - pos_a : len_b - pos_b;
			a->movement = 2;
		}
	if (((pos_a > len_a / 2 ? len_a - pos_a : pos_a) + (pos_b > len_b / 2 ? len_b - pos_b : pos_b)) < a->cost)
		{
			a->cost = ((pos_a > len_a / 2 ? len_a - pos_a : pos_a) + (pos_b > len_b / 2 ? len_b - pos_b : pos_b));
			a->movement = 3;
		}
	a->cost++;
	return (a->cost);
}
*/


int	decide_movement(int *pos_a, int pos_b, int len_a, int len_b)
{
	int	cost_rr;
	int	cost_rrr;
	int cost_sep_ways;
	
	cost_rr = (*pos_a > pos_b) ? *pos_a : pos_b;	
	cost_rrr = ((len_a - *pos_a > len_b - pos_b) ? len_a - *pos_a : len_b - pos_b);
	cost_sep_ways = (*pos_a > len_a / 2 ? len_a - *pos_a : *pos_a);
	cost_sep_ways += (pos_b > len_b / 2 ? len_b - pos_b : pos_b);
	//printf("going to locate at %d in b. cost rr %d cost rrr %d cost sep_ways %d\n",pos_b, cost_rr, cost_rrr, cost_sep_ways);
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

int ft_cost_element(t_stack *stack_a, t_stack *stack_b, int pos_a, int a_value)
{
	int	len_b;
	int	len_a;
	//printf("How much cost?\n");
	len_b = count_elements(stack_b);
	len_a = count_elements(stack_a);
	while (stack_a->content != a_value)
		stack_a = stack_a->next;
	stack_a->place_to_go = find_destination(a_value, stack_b, 'b');
	stack_a->movement = decide_movement(&pos_a, stack_a->place_to_go , len_a, len_b);
	stack_a->cost = (pos_a);
	//if (a_value == 8)
	//{
	//	printf("best movement %d - Moving to %d pos in ", a_value, pos_a);
	//	ft_print_stack(stack_b, 'b');
	//	printf("Movement %d, cost %d\n", stack_a->movement, stack_a->cost);
	//}
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
		cost = ft_cost_element(stack_a, stack_b, pos_a, temp->content);
		if (cost < min_cost)
		{
			min_cost = cost;
			min_cost_position = pos_a;
		}
		temp = temp->next;
		pos_a++;
	}
	//printf("Min cos position is %d, cost is %d\n", min_cost_position, min_cost);
	//printf("\n");
	return (min_cost_position);
}
