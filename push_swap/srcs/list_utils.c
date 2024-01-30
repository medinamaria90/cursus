/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:45:48 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/19 09:46:14 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_node_back(t_stack **lst, t_stack *new)
{
	t_stack	*templst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	templst = *lst;
	while ((templst)->next != NULL)
		templst = templst->next;
	templst->next = new;
}

void	ft_add_node_front(t_stack **lst, t_stack *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new -> next = *lst;
	*lst = new;
}

t_stack	*ft_new_node(int content)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

int	ft_add_node(int content, t_stack **lst)
{
	t_stack	*new;
	t_stack	*temp;

	temp = *lst;
	while(temp != NULL)
	{
		if (temp->content == content)
			return (-1);
		temp = temp->next;
	}
	new = ft_new_node(content);
	if (new == NULL)
		return (-1);
	ft_add_node_back(lst, new);
	return (0);
}
t_stack	*ft_lastnode(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}