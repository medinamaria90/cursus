/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:15:42 by marimedi          #+#    #+#             */
/*   Updated: 2023/11/28 14:35:24 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (n > i)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

#include <stdio.h>
#include <string.h>
int	main(void)
{
	char str1[] = "1234567";
	char str2[] = "1234567";
	
	bzero(&str1[2], 2);
	ft_bzero(&str2[2], 2);
	printf("%s\n", str1);
	printf("%s\n", str2);
	return (0);
}
