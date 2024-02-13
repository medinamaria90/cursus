/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:23:39 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/13 11:53:48 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap_boths(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}

void	check_if_ordered(t_stack *stack_a, t_stack *stack_b)
{
	if (is_ordered(stack_a) == 0 && count_elements(stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	rotate_instruction(t_stack **stack_a, t_stack **stack_b, int rotation)
{
	if (rotation == 1)
	{
		ft_rrotate(stack_a);
		ft_rrotate(stack_b);
	}
	else if (rotation == 2)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
}

int	do_movement(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		ft_push(stack_a, stack_b, 1);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		ft_push(stack_b, stack_a, 1);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		ft_swap(stack_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		ft_swap(stack_b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ft_rotate(stack_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		ft_rotate(stack_b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		ft_rrotate(stack_a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		ft_rrotate(stack_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rotate_instruction(stack_a, stack_b, 1);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rotate_instruction(stack_a, stack_b, 2);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ft_swap_boths(stack_b, stack_a);
	else
		return (-1);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*instruction;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	if (process_input(argv, &stack_a) == -1)
		return (1);
	instruction = get_next_line(0);
	while (instruction != NULL)
	{
		if (do_movement(instruction, &stack_a, &stack_b) == -1)
		{
			free (instruction);
			free_stack(&stack_a);
			free_stack(&stack_b);
			return (ft_return_error());
		}
		free(instruction);
		instruction = get_next_line(0);
	}
	check_if_ordered(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
