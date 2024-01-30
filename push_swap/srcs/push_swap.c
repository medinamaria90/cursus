/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:00:57 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/30 13:24:39 by marimedi         ###   ########.fr       */
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

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	counter;
	int	position;
	t_stack *temp;

	while (count_elements(*stack_b) != 0)
	{
		if (count_elements(*stack_a) == 3)
		{
			ft_print_stack(*stack_a, 'a');
			ft_print_stack(*stack_b, 'b');
			ft_sort_three(stack_a);
			ft_push_back(stack_a, stack_b);
		}
		else
		{
			position = find_cheapest_movement(*stack_a, *stack_b);
			temp = *stack_a;
			counter = 0;
			while (temp && position > counter)
			{
				temp = temp->next;
				counter++;
			}
			ft_move(stack_a, stack_b, position, (temp)->movement);
		}	
	}
}
void first_movements(t_stack **stack_a, t_stack **stack_b, int n)
{
	if (n == 2 && is_ordered(*stack_a) == 1)
	{
		printf("sa\n");
		ft_swap(stack_a);
	}
	else if (n == 3 && is_ordered(*stack_a) == 1)
		ft_sort_three(stack_a);
	if (n == 4)
	{
		printf("pb\n");
		ft_push(stack_b, stack_a, 1);
		n--;
	}
	else if (n > 4)
	{
		printf("pb\npb\n");
		ft_push(stack_b, stack_a, 2);
	}
}

int	main(int argc, char *argv[])
{
	int 	n;
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc == 1)
		return (ft_return_error());
	stack_a = NULL;
	stack_b = NULL;
	n = process_input(argv, &stack_a);
	if (n == -1)
		return (1);
	else if (n == 1)
		return (0);
	first_movements(&stack_a, &stack_b, n);
	if (is_ordered(stack_a) == 1)
		ft_sort(&stack_a, &stack_b);
	//printf("Final result:\n");
	//ft_print_stack(stack_a, 'A');
	(void) argc;
	return (0);
}
