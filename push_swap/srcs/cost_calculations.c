/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:19:44 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/03 21:01:29 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_cost_rr(int pos_a, int len_a, int pos_b, int len_b)
{
	if ((len_a - pos_a > len_b - pos_b))
		return (len_a - pos_a);
	else
		return (len_b - pos_b);
}

int	calc_cost_rrr(int pos_a, int pos_b)
{
	if (pos_a > pos_b)
		return (pos_a);
	else
		return (pos_b);
}

int	calc_cost_sep_ways(int pos_a, int len_a, int pos_b, int len_b)
{
	int	cost_a;
	int	cost_b;

	if (pos_b > (len_b / 2))
		cost_b = len_b - pos_b;
	else
		cost_b = pos_b;
	if (pos_a > (len_a / 2))
		cost_a = len_a - pos_a;
	else
		cost_a = pos_a;
	return (cost_a + cost_b);
}

void	save_calculations(t_stack *stack_a, int pos_a, int cost, int movement)
{
	int	pos;

	pos = 0;
	while (pos < pos_a)
	{
		stack_a = stack_a->next;
		pos++;
	}
	stack_a->cost = cost;
	stack_a->movement = movement;
}

void	best_movement(t_stack *stack_a, int pos_a, t_stack *stack_b, int pos_b)
{
	int	cost_rr;
	int	cost_rrr;
	int	cost_sep_ways;
	int	len_a;
	int	len_b;

	len_b = count_elements(stack_b);
	len_a = count_elements(stack_a);
	cost_rrr = calc_cost_rrr(pos_a, pos_b);
	cost_rr = calc_cost_rr(pos_a, len_a, pos_b, len_b);
	cost_sep_ways = calc_cost_sep_ways(pos_a, len_a, pos_b, len_b);
	if (cost_rrr <= cost_rr && cost_rrr <= cost_sep_ways)
		save_calculations(stack_a, pos_a, cost_rrr + 1, 1);
	else if (cost_rr <= cost_rrr && cost_rr <= cost_sep_ways)
		save_calculations(stack_a, pos_a, cost_rr + 1, 2);
	else
		save_calculations(stack_a, pos_a, cost_sep_ways + 1, 3);
}
