/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:19:44 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/19 09:46:11 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_count_elements(t_stack *stack)
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


int	ft_cheapest_movement(t_stack **a, t_stack **b)
{
	int	pos_a;
	int	cost;
	int	min_cost;
	int	min_cost_pos;
	t_stack	*temp;

	temp = *a;
	min_cost = INT_MAX;
	pos_a = 0;
	while (temp != NULL)
	{
		cost = ft_cost_element(*a, *b, pos_a, temp->content);
		if (cost < min_cost)
		{
			min_cost = cost;
			min_cost_pos = pos_a;
		}
		temp = temp->next;
		pos_a++;
	}
	return (min_cost_pos);
}
