/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:20:45 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/12 10:57:40 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elms, size_t size)
{
	void	*str;

	str = (void *)malloc(size * num_elms);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size * num_elms);
	return (str);
}
