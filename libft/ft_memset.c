/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:20:54 by marimedi          #+#    #+#             */
/*   Updated: 2023/11/28 14:26:17 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

#include <string.h>
#include <stdio.h>
int	main(void)
{
	//Testing '1'
	//The result is not null terminated, so I doesnt have to the the same.//
	char str1[] = "H";
	char str2[] = "H";
	printf("%c", ((char*)ft_memset(str1, 'e', 2))[0]);
	printf("%c\n", ((char*)ft_memset(str1, 'e', 2))[1]);
	printf("%c", ((char*)memset(str2, 'e', 2))[0]);
	printf("%c\n", ((char*)memset(str2, 'e', 2))[1]);
	
	//Testing '2'
	char str3[] = "Hola que tal amigosss";
	char str4[] = "Hola que tal amigosss";
	ft_memset(str3, 'e', 2);
	memset(str4, 'e', 2);
	printf("%s\n", str3);
	printf("%s\n", str4);
	
	//Testing '3'
	int number = 1009;
	int* ptr1 = &number;
	int* ptr2 = &number;
	printf("%s\n", (char*)memset(ptr1, 'e', 2));
	printf("%s\n", (char*)memset(ptr2, 'e', 2));
}
