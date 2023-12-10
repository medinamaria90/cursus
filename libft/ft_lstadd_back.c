/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:08:48 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/10 19:22:51 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*templst;

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
/*
int	main(void)
{
	//char	*elem0 = "Hola";
	char	*elem1 = "Que";
	char	*elem2 = "Tal";
	t_list	*node0 = NULL;
	t_list	*node1 = ft_lstnew(elem1);
	t_list	*node2 = ft_lstnew(elem2);
	ft_lstadd_back(&node0, node1);
	ft_lstadd_back(&node1, node2);
	printf("Function worked\n");
	printf("The first node is: %s\n", (char *)node0->content);
	printf("The second node is: %s\n", (char *)node0->next->content);
	printf("The third node is: %s\n", (char *)node0->next->next);
	//printf("The node after last node is: %s\n", (char*)ft_lstlast(node0)->next);
}
*/