/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:04:56 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/19 09:45:51 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_last_push(t_stack a, t_stack b);

void ft_reverse_rotate_al(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	while (pos_a > 0 && pos_b > 0)
	{
		printf("rr\n");
		ft_rrotate(a);
		ft_rrotate(b);
		ft_print_stack(*a, 'A');
		pos_a--;
		pos_b--;
	}
	while (pos_a > 0)
	{
		printf("ra\n");
		ft_rrotate(a);
		ft_print_stack(*a, 'A');
		pos_a--;
	}
	while (pos_b > 0)
	{
		printf("rb\n");
		ft_rrotate(b);
		ft_print_stack(*a, 'A');
		pos_b--;
	}
	printf("pa\n");
	ft_push(b, a, 1);
	ft_print_stack(*a, 'A');	
}

void ft_rotate_al(t_stack **a, t_stack **b, int rotations_a, int rotations_b)
{
	while (rotations_a > 0 && rotations_b > 0)
	{
		printf("rrr\n");
		ft_rotate(a);
		ft_rotate(b);
		//ft_print_stack(*a, 'A');
		rotations_a--;
		rotations_b--;
	}
	while (rotations_a > 0)
	{
		printf("rra\n");
		ft_rotate(a);
		//ft_print_stack(*a, 'A');
		rotations_a--;
	}
	while (rotations_b > 0)
	{
		printf("rrb\n");
		
		ft_rotate(b);
		//ft_print_stack(*a, 'A');
		rotations_b--;
	}
	printf("pa\n");
	ft_push(b, a, 1);
	//ft_print_stack(*a, 'A');
}

void ft_best_movement(t_stack **stack, int pos, int len, int name) 
{
    if (len / 2 < pos) 
	{
        while (pos < len) 
		{
            printf("rr%c\n", name);
            ft_rotate(stack);
			//ft_print_stack(*stack, name);
            pos++;
        }
    } 
	else 
	{
        while (pos > 0) 
		{
            printf("r%c\n", name);
            ft_rrotate(stack);
			//ft_print_stack(*stack, name);
            pos--;
        }    
	}
}

void ft_move(t_stack **a, t_stack **b, int pos_a, int movement)
{
	int	pos_b;
	int len_a;
	int	len_b;

	pos_b = (*a)->place_to_go;
	len_a = ft_count_elements(*a);
	len_b = ft_count_elements(*b);
	if (movement == 1)
		ft_reverse_rotate_al(a, b, pos_a, pos_b);
	else if (movement == 2)
		ft_rotate_al(a, b, len_a - pos_a, len_b - pos_b);
	else if (movement == 3)
	{
		ft_best_movement(a, pos_a, len_a, 'a');
		ft_best_movement(b, pos_b, len_b, 'b');
		printf("pa\n");
		ft_push(b, a, 1);
		//ft_print_stack(*a, 'A');
	}
}

