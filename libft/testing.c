/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:09:57 by marimedi          #+#    #+#             */
/*   Updated: 2023/11/29 15:42:05 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
	printf("\nTesting\n");
	
	printf("Strlen --> ");
    char *test_cases[] = {
        "Hola",
        "12345",
        "ABCDE",
        "",
        "Test123",
    };
    for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); ++i) 
	{
        size_t result_libft = ft_strlen(test_cases[i]);
        size_t result_standard = strlen(test_cases[i]);
        if (result_libft == result_standard) 
            printf("✔");
	   	else 
            printf("✖");
    }

	printf("\nMemset --> ");
	char str1[] = "Hola !Adios";
	char str2[] = "Hola !Adios";
	memset(str1, 'a', 4);
	ft_memset(str2, 'a', 4);
	if (strcmp(str1, str2) == 0)
    	printf("✔");
	else
    	printf("✖");
	
	memset(str1, 'z', 1);
	ft_memset(str2, 'z', 1);
	if (strcmp(str1, str2) == 0)
    	printf("✔");
	else
	{
		printf("\n");
		printf("Expected %s -- Output %s\n", str1, str2);
	}	
    

	return 0;
}
