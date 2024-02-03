/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:04:56 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/03 21:12:11 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	place_to_go(t_stack *stack, int pos_a)
{
	int	count;

	count = 0;
	while (stack && count < pos_a)
	{
		stack = stack->next;
		count++;
	}
	return ((stack)->go_to);
}

void	ft_rotate_al(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	while (pos_a > 0 && pos_b > 0)
	{
		write(1, "rr\n", 3);
		ft_rotate(a);
		ft_rotate(b);
		pos_a--;
		pos_b--;
	}
	while (pos_a > 0)
	{
		write(1, "ra\n", 3);
		ft_rotate(a);
		pos_a--;
	}
	while (pos_b-- > 0)
	{
		write(1, "rb\n", 3);
		ft_rotate(b);
	}
	write(1, "pb\n", 3);
	ft_push(b, a, 1);
}

void	ft_reverse_rotate_al(t_stack **a, t_stack **b, int rot_a, int rot_b)
{
	while (rot_a > 0 && rot_b > 0)
	{
		write(1, "rrr\n", 4);
		ft_rrotate(a);
		ft_rrotate(b);
		rot_a--;
		rot_b--;
	}
	while (rot_a > 0)
	{
		write(1, "rra\n", 4);
		ft_rrotate(a);
		rot_a--;
	}
	while (rot_b-- > 0)
	{
		write(1, "rrb\n", 4);
		ft_rrotate(b);
	}
	write(1, "pb\n", 3);
	ft_push(b, a, 1);
}

void	move_diff_directions(t_stack **stack, int pos, int len, int name)
{
	if (len / 2 < pos)
	{
		while (pos < len)
		{
			write(1, "rr", 2);
			write(1, &name, 1);
			write(1, "\n", 1);
			ft_rrotate(stack);
			pos++;
		}
	}
	else
	{
		while (pos-- > 0)
		{
			write(1, "r", 1);
			write(1, &name, 1);
			write(1, "\n", 1);
			ft_rotate(stack);
		}
	}
}

void	ft_move(t_stack **stack_a, t_stack **stack_b, int pos_a, int movement)
{
	int	pos_b;
	int	len_a;
	int	len_b;

	pos_b = place_to_go(*stack_a, pos_a);
	len_a = count_elements(*stack_a);
	len_b = count_elements(*stack_b);
	if (movement == 1)
		ft_rotate_al(stack_a, stack_b, pos_a, pos_b);
	else if (movement == 2)
		ft_reverse_rotate_al(stack_a, stack_b, len_a - pos_a, len_b - pos_b);
	else if (movement == 3)
	{
		move_diff_directions(stack_a, pos_a, len_a, 'a');
		move_diff_directions(stack_b, pos_b, len_b, 'b');
		write(1, "pb\n", 3);
		ft_push(stack_b, stack_a, 1);
	}
}
