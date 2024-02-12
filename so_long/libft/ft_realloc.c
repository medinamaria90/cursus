/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:34:22 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/12 14:06:17 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	if (ptr == NULL)
		return (malloc(size));
	new_ptr = malloc(size);
	if (new_ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	ft_memmove(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
