/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:34:19 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/11 11:41:40 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	if (lst == NULL)
		return (0);
	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
/*
int	main(void)
{
	char *str1 = "Hola";
	char *str2 = "Que";
	char *str3 = "Tal";
	t_list *node1;
	t_list *node2;
	t_list *node3;

	node1 = ft_lstnew(str1);
	node2 = ft_lstnew(str2);
	node3 = ft_lstnew(str3);
	node2->next = node3;
	node1->next = node2;
	printf("%d\n", ft_lstsize(node1));
}
*/