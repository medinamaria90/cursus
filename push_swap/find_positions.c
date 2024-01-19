/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:39:21 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/19 09:45:59 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//If to return is 1, we return the min value, if is 2, we return the min position
int	ft_find_min(t_stack *stack, int to_return)
{
	t_stack	*temp;
	int		min;
	int		min_pos;
	int		count;

	temp = stack;
	min = stack->content;
	min_pos = 1;
	count = 1;
	while (temp != NULL)
	{
		if (temp->content < min)
		{
			min = temp->content;
			min_pos = count;
		}
		count++;
		temp = temp->next;
	}
	if (to_return == 1)
		return (min_pos);
	return (min);
	
}

int	ft_find_max(t_stack *stack, int to_return)
{
	t_stack	*temp;
	int		max;
	int		max_post;
	int		count;

	temp = stack;
	max = stack->content;
	max_post = 1;
	count = 1;
	while (temp != NULL)
	{
		if (temp->content > max)
		{
			max = temp->content;
			max_post = count;
		}
		count++;
		temp = temp->next;
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
		//printf("elm (%d) < value(%d) AND value(%d) <= above value(%d)\n", elm, stack->content, stack->content, above_value);
		if (elm < stack->content && (above_value == elm || stack->content < above_value))
		{
			above_pos = pos;
			above_value = stack->content;
		//	printf("Yes, above value is %d\n", above_value);
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

	//printf("In find below\n");
	below_pos = 0;
	pos = 0;
	below_value = elm - 1;
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

// If dest == a, we want to find the right pos of elm in 'a'
int	ft_find_pos(int elm, t_stack *stack, int dest)
{
	int	pos;
	//ft_print_stack(stack, dest);
	pos = 0;
	if (dest == 'b')
	{
		if (ft_find_min(stack, 2) > elm)
			pos = ft_find_max(stack, 1) - 1;
		else
		{
			pos = ft_find_below(elm, stack);
		}
	}
	else if (dest == 'a')
	{
		if (ft_find_max(stack, 2) < elm)
		{

			pos = ft_find_min(stack, 1) - 1;
		}
		else
		{
			pos = ft_find_above(elm, stack);
		}
	}
	return (pos);
}