/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:18:45 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/09 11:42:56 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_ordered(t_stack *a)
{
	while (a -> next)
	{
		if (a->content > a->next->content)
			return (1);
		a = a->next;
	}
	return (0);
}

void	ft_swap(t_stack **stack)
{
	t_stack	*second;
	t_stack	*third;

	if (count_elements(*stack) < 2)
		return ;
	second = *stack;
	third = ((*stack)->next)->next;
	*stack = ((*stack))->next;
	(*stack)->next = second;
	second->next = third;
}

void	ft_rrotate(t_stack **stack)
{
	t_stack	*lastnode;
	t_stack	*secondlast;
	t_stack	*temp;

	if (count_elements(*stack) == 0 || count_elements(*stack) == 1)
		return ;
	lastnode = *stack;
	while (lastnode->next != NULL)
	{
		secondlast = lastnode;
		lastnode = lastnode->next;
	}
	temp = *stack;
	*stack = lastnode;
	(*stack)->next = temp;
	secondlast->next = NULL;
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*temp;

	if (count_elements(*stack) == 0 || count_elements(*stack) == 1)
		return ;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first_node = *stack;
	*stack = first_node->next;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first_node;
	first_node->next = NULL;
}

void	ft_push(t_stack **dst, t_stack **src, int times)
{
	t_stack	*to_push;

	if (count_elements(*src) == 0)
		return ;
	while (times > 0)
	{
		to_push = *src;
		*src = (*src)->next;
		to_push->next = NULL;
		ft_add_node_front(dst, to_push);
		times--;
	}
}
