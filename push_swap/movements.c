/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:04:56 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/26 11:42:12 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rotate_al(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	while (pos_a-- > 0 && pos_b-- > 0)
	{
		printf("rr\n");
		ft_rotate(a);
		ft_rotate(b);
	}
	while (pos_a-- > 0)
	{
		printf("rra\n");
		ft_rrotate(a);
	}
	while (pos_b-- > 0)
	{
		printf("rb\n");
		ft_rotate(b);
	}
	printf("pb\n");
	ft_push(b, a, 1);
}

void ft_reverse_rotate_al(t_stack **a, t_stack **b, int rotations_a, int rotations_b)
{
	while (rotations_a-- > 0 && rotations_b-- > 0)
	{
		printf("rrr\n");
		ft_rrotate(a);
		ft_rrotate(b);
	}
	while (rotations_a-- > 0)
	{
		printf("rra\n");
		ft_rrotate(a);
	}
	while (rotations_b-- > 0)
	{
		printf("rrb\n");
		ft_rrotate(b);
	}
	printf("pb\n");
	ft_push(b, a, 1);
}

void ft_best_movement(t_stack **stack, int pos, int len, int name) 
{
    if (len / 2 < pos) 
	{
        while (pos++ < len) 
		{
            printf("rr%c\n", name);
            ft_rrotate(stack);
        }
    } 
	else 
	{
        while (pos-- > 0) 
		{
            printf("r%c\n", name);
            ft_rotate(stack);
        }    
	}
}

void ft_move(t_stack **stack_a, t_stack **stack_b, int pos_a, int movement)
{
	int	pos_b;
	int len_a;
	int	len_b;
	t_stack	*temp;

	temp = *stack_a;
	len_a = 0;
	while (temp && len_a < pos_a)
	{
		temp = temp->next;
		len_a++;
	}
	//printf("Pos elm a to move is %d\n", pos_a);
	pos_b = (temp)->place_to_go;
	len_a = count_elements(*stack_a);
	len_b = count_elements(*stack_b);
	if (movement == 1)
		ft_rotate_al(stack_a, stack_b, pos_a, pos_b);
	else if (movement == 2)
		ft_reverse_rotate_al(stack_a, stack_b, len_a - pos_a, len_b - pos_b);
	else if (movement == 3)
	{
		ft_best_movement(stack_a, pos_a, len_a, 'a');
		ft_best_movement(stack_b, pos_b, len_b, 'b');
		printf("pb\n");
		ft_push(stack_b, stack_a, 1);
	}
}

