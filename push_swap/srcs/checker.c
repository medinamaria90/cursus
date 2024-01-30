/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:23:39 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/30 12:53:39 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_stack(t_stack *stack, int name) 
{
   printf("Stack %c: ", name);
    while (stack != NULL) {
        printf("%d ", stack->content);
        stack = stack->next;
    }
   printf("\n");
}

void	check_if_ordered(t_stack *stack_a)
{
	if (is_ordered(stack_a) == 0)
		printf("OK\n");
	else
		printf("KO\n");
	//printf("\n%d\n", is_ordered(stack_a));
}

void	rotate_instruction (t_stack **stack_a, t_stack **stack_b, int rotation)
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

void	do_movement(char *line, t_stack **stack_a, t_stack **stack_b)
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
}


int	main(int argc, char *argv[])
{
	char *instruction;
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc == 1)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	if (process_input(argv, &stack_a) == -1)
		return (1);
	instruction = NULL;
	instruction = get_next_line(0);
	if (!instruction)
		return (1);
	while (1)
	{
		do_movement(instruction, &stack_a, &stack_b);
		free(instruction);
		instruction = get_next_line(0);
		if (!instruction)
			break ;
	}
	check_if_ordered(stack_a);
	return (0);
}
