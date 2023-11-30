/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:18:33 by marimedi          #+#    #+#             */
/*   Updated: 2023/11/29 20:43:58 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src < dest)
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
		return (dest);
	}
	else if (src >= dest)
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char src[50] = "HolaDonPepito";
	char *dest = src + 2;
	ft_memmove(dest, src, 5);
	printf("dest: %s\n", dest);	
	char src2[50] = "HolaDonPepito";
	char *dest2 = src2 + 2;
	memmove(dest2, src2, 5);
	printf("dest: %s\n", dest2);
}
*/