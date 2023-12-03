/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:46:43 by marimedi          #+#    #+#             */
/*   Updated: 2023/11/07 17:46:24 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i <= len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[j + i] == little[j]
				&& (j + i) < len)
			{
				if (little[j] == '\0' || little[j + 1] == '\0')
					return ((char *)&big[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
