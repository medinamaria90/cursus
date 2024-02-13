/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:03:54 by marimedi          #+#    #+#             */
/*   Updated: 2023/11/30 16:03:54 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size < dest_len || size == 0)
		return (src_len + size);
	count = 0;
	while (src[count])
	{
		if (dest_len + count < size - 1)
			dest[count + dest_len] = src[count];
		count++;
	}
	if (size > src_len + dest_len)
		dest[src_len + dest_len] = '\0';
	else if (size > dest_len)
		dest[size - 1] = '\0';
	return (src_len + dest_len);
}
