/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:01:55 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/09 11:45:42 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	count;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	count = 0;
	while (n > count)
	{
		if ((unsigned char)str1[count] != (unsigned char)str2[count])
			return ((unsigned char)str1[count] - (unsigned char)str2[count]);
		count ++;
	}
	return (0);
}
