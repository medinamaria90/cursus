/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:00:57 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/25 21:16:44 by marimedi         ###   ########.fr       */
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

int	ft_is_ordered(t_stack *a)
{
	while (a -> next)
	{
		if (a->content > a->next->content)
			return (1);	
		a = a->next;			
	}
	return (0);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b, int len_a)
{
	int	counter;
	int	position;
	t_stack *temp;
	
	if (len_a == 4)
	{
		printf("pb\n");
		ft_push(stack_b, stack_a, 1);
		len_a--;
	}
	else if (len_a > 4)
	{
		printf("pb\npb\n");
		ft_push(stack_b, stack_a, 2);
	}
	while (count_elements(*stack_b) != 0)
	{
		if (count_elements(*stack_a) == 3)
		{
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
			//printf("After the while\n");
			//printf("item to move %d\n", position);
			//printf("place to move %d\n", temp->place_to_go);
			//printf("Movement %d\n", temp->movement);
			ft_move(stack_a, stack_b, position, (temp)->movement);
		}
			
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
	else if (n == 2 && ft_is_ordered(stack_a) == 1)
		ft_swap(&stack_a);
	else if (n == 3 && ft_is_ordered(stack_a) == 1)
		ft_sort_three(&stack_a);
	else if (ft_is_ordered(stack_a) == 1)
		ft_sort(&stack_a, &stack_b, n);
	//printf("Final result:\n");
	//ft_print_stack(stack_a, 'A');
	(void) argc;
	return (0);
}
