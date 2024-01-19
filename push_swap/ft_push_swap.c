/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:00:57 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/19 09:46:06 by marimedi         ###   ########.fr       */
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

void	ft_sort(t_stack **a, t_stack **b, int len_a)
{
	int	min_cost_pos;
	
	if (len_a == 3)
		ft_sort_three(a);
	else if (len_a == 4)
	{
		printf("pb\n");
		ft_push(b, a, 1);
		len_a--;
	}
	else if (len_a > 4)
	{
		printf("pb\n");
		printf("pb\n");
		ft_push(b, a, 2);
	}
	while (ft_count_elements(*b) != 0)
	{
		if (ft_count_elements(*a) == 3)
		{
			ft_sort_three(a);
			ft_push_back(a, b);
		}
		else
		{
			min_cost_pos = ft_cheapest_movement(a, b);
			ft_move(a, b, min_cost_pos, (*a)->movement);
		}
	}
}

int	main(int argc, char *argv[])
{
	int 	n;
	int		i;
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	n = 1;
	while (argv[n])
	{
		if (ft_save_int(argv[n], &i) == -1)
			return (ft_return_error());
		if (ft_add_node(i, &stack_a) == -1)
			return (ft_return_error());
		n++;
	}
	if (n - 1 == 1)
		return (0);
	else if (n - 1 == 2 && ft_is_ordered(stack_a) == 1)
		ft_swap(&stack_a);
	else if (ft_is_ordered(stack_a) == 1)
		ft_sort(&stack_a, &stack_b, n - 1);
	//printf("Final result:\n");
	//ft_print_stack(stack_a, 'A');
	(void) argc;
	return (0);
}
