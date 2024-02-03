/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:00:57 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/03 20:59:00 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_movement_costs(t_stack *stack_a, t_stack *stack_b)
{
	int		pos_a;
	t_stack	*temp;

	temp = stack_a;
	pos_a = 0;
	while (temp != NULL)
	{
		temp->go_to = find_destination(temp->content, stack_b, 'b');
		best_movement(stack_a, pos_a, stack_b, temp->go_to);
		temp = temp->next;
		pos_a++;
	}
}

void	get_cheapest(t_stack *stack_a, int *cheap_pos, int *movement)
{
	int	cost;
	int	pos;

	cost = stack_a->cost + 1;
	pos = 0;
	while (stack_a)
	{
		if (stack_a->cost < cost)
		{
			cost = stack_a->cost;
			*cheap_pos = pos;
			*movement = stack_a->movement;
		}
		stack_a = stack_a->next;
		pos++;
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		position;
	int		movement;

	while (count_elements(*stack_b) != 0)
	{
		if (count_elements(*stack_a) == 3)
		{
			ft_sort_three(stack_a);
			ft_push_back(stack_a, stack_b);
		}
		else
		{
			calc_movement_costs(*stack_a, *stack_b);
			get_cheapest(*stack_a, &position, &movement);
			ft_move(stack_a, stack_b, position, movement);
		}
	}
}

void	first_movements(t_stack **stack_a, t_stack **stack_b, int n)
{
	if (n == 2 && is_ordered(*stack_a) == 1)
	{
		write(1, "sa\n", 3);
		ft_swap(stack_a);
	}
	else if (n == 3 && is_ordered(*stack_a) == 1)
		ft_sort_three(stack_a);
	if (n == 4)
	{
		write(1, "pb\n", 3);
		ft_push(stack_b, stack_a, 1);
	}
	else if (n > 4)
	{
		write(1, "pb\npb\n", 6);
		ft_push(stack_b, stack_a, 2);
	}
}

int	main(int argc, char *argv[])
{
	int		n;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	n = process_input(argv, &stack_a);
	if (n == -1)
		return (1);
	if (is_ordered(stack_a) == 1)
		first_movements(&stack_a, &stack_b, n);
	if (is_ordered(stack_a) == 1 || count_elements(stack_b) != 0)
		ft_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
