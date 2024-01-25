/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:39:21 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/25 22:08:29 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min(t_stack *stack, int to_return)
{
	int		min;
	int		min_pos;
	int		count;

	min = stack->content;
	min_pos = 1;
	count = 1;
	while (stack != NULL)
	{
		if (stack->content < min)
		{
			min = stack->content;
			min_pos = count;
		}
		count++;
		stack = stack->next;
	}
	if (to_return == 1)
		return (min_pos);
	return (min);
	
}

int	ft_find_max(t_stack *stack, int to_return)
{
	int		max;
	int		max_post;
	int		count;

	max = stack->content;
	max_post = 1;
	count = 1;
	while (stack != NULL)
	{
		if (stack->content > max)
		{
			max = stack->content;
			max_post = count;
		}
		count++;
		stack = stack->next;
	}
	if (to_return == 1)
		return (max_post);
	return (max);
}

int	ft_find_above(int elm, t_stack *stack)
{
	int		pos;
	int		above_pos;
	int		above_value;

	above_pos = 0;
	pos = 0;
	above_value = elm;
	while (stack != NULL)
	{
		if (elm < stack->content && (above_value == elm || stack->content < above_value))
		{
			above_pos = pos;
			above_value = stack->content;
		}
		stack= stack->next;
		pos++;
	}

	return (above_pos);
}

int	ft_find_below(int elm, t_stack *stack)
{
	int		pos;
	int		below_pos;
	int		below_value;

	below_pos = 0;
	pos = 0;
	below_value = INT_MIN;
	while (stack != NULL)
	{
		if (elm > stack->content && stack->content >= below_value)
		{
			below_pos = pos;
			below_value = stack->content;
		}
		stack= stack->next;
		pos++;
	}
	return (below_pos);
}

int	find_destination(int elm, t_stack *stack, int dest)
{
	int	pos;

	pos = 0;
	if (dest == 'b')
	{
		if (ft_find_min(stack, 2) > elm)
			pos = ft_find_max(stack, 1) - 1;
		else
			pos = ft_find_below(elm, stack);
	}
	else if (dest == 'a')
	{
		if (ft_find_max(stack, 2) < elm)
			pos = ft_find_min(stack, 1) - 1;
		else
			pos = ft_find_above(elm, stack);
	}
	return (pos);
}
