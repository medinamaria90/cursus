/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:49:12 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/09 11:44:31 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n - 1 && src[count] && n != 0)
	{
		if (src[count])
			dest[count] = src[count];
		else
			dest[count] = '\0';
		count ++;
	}
	if (n != 0)
		dest[count] = '\0';
	while (src[count])
	{
		count++;
	}
	return (count);
}
