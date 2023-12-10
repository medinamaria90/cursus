/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:30:55 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/10 12:07:20 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	char	*elem0 = "Hola";
	char	*elem1 = "Que";
	char	*elem2 = "Tal";
	t_list	*node0 = ft_lstnew(elem0);
	t_list	*node1 = ft_lstnew(elem1);
	t_list	*node2 = ft_lstnew(elem2);
	ft_lstadd_front(&node2, node1);
	ft_lstadd_front(&node1, node0);
	printf("The last node is: %s\n", (char*)ft_lstlast(node0)->content);
	printf("The node after last node is: %s\n", (char*)ft_lstlast(node0)->next);
}
*/