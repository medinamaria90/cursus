/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:13:45 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/09 11:47:53 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*root;

	root = NULL;
	ft_lstadd_front(&root, ft_lstnew("Hola "));
	ft_lstadd_front(&root, ft_lstnew(" Que "));
	ft_lstadd_front(&root, ft_lstnew(" tal "));
	t_list *current = root;
	while (current != NULL) 
    {
		printf("%s", (char *)current->content);
		current = current->next;
    }
}
*/