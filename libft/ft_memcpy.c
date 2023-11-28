/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:38:00 by marimedi          #+#    #+#             */
/*   Updated: 2023/11/28 21:48:25 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	
	i = 0;
	while (i < n)
	{	
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return(dest);
}

#include <string.h>
#include <stdio.h>
int	main(void)
{
	//TEST 1
	char *src = "Hello!";
	char dest[5];
	char dest_[5];
	size_t n = 3;
	memcpy(dest, src, n);
	ft_memcpy(dest_, src, n);
	printf("The lib function :%s\n", dest);
	printf("My function: %s\n", dest_);

	//TEST 2
	int src2 = 10257;
	int dest2;
	int dest2_;
	size_t n2 = 4;
	memcpy(&dest2, &src2, n2);
	ft_memcpy(&dest2_, &src2, n2);
	printf("The lib function %i\n", dest2);
	printf("My function %i\n", dest2_);
	
	//TEST 3
	char *src3 = "";
	char *dest3 = "";
	char *dest3_ = "";
	size_t n3 = 4;
	memcpy(dest3, src3, n3);
	ft_memcpy(dest3_, src3, n3);
	printf("The lib function %s\n", dest3);
	printf("My function %s\n", dest3_);
}
