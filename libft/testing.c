/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:09:57 by marimedi          #+#    #+#             */
/*   Updated: 2023/11/29 21:46:37 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
#include <bsd/string.h>

void test_strlcpy(char *src, char*dst, size_t size) 
{
    char dest[20];
    char dest_official[20];

    strcpy(dest, dst);
    strcpy(dest_official, dst);

    ft_strlcpy(dest, src, size);
    strlcpy(dest_official, src, size);
    if (strcmp(dest, dest_official) == 0)
        printf("✔");
    else {
        printf("✖");
        printf("Expected: %s // Output: %s\n", dest_official, dest);
    }
}

void test_strlen(char *test_case) 
{
    size_t result_libft = ft_strlen(test_case);
    size_t result_standard = strlen(test_case);

    if (result_libft == result_standard)
        printf("✔");
    else
        printf("✖");
}

void test_memset(char *str, int val, size_t len) 
{
    char str1[20];
    char str2[20];

    strcpy(str1, str);
    strcpy(str2, str);

    memset(str1, val, len);
    ft_memset(str2, val, len);

    if (strcmp(str1, str2) == 0)
        printf("✔");
    else
        printf("✖");
}

void test_memcpy(char *dest, char *src, size_t len) 
{
    char dest1[20];
    char dest2[20];
    strcpy(dest1, dest);
    strcpy(dest2, dest);

    memcpy(dest1, src, len);
    ft_memcpy(dest2, src, len);

    if (strcmp(dest1, dest2) == 0)
        printf("✔");
    else 
    {
        printf("✖\n");
        printf("Expected: %s // Output: %s\n", dest1, dest2);
    }
}

void test_memmove(char *dest, char *src, size_t len) 
{
    char dest1[20];
    char dest2[20];
    strcpy(dest1, dest);
    strcpy(dest2, dest);

    memmove(dest1, src, len);
    ft_memmove(dest2, src, len);

    if (strcmp(dest1, dest2) == 0)
        printf("✔");
    else {
        printf("✖\n");
        printf("FAIL!!! Expected %s -- Output %s\n", dest1, dest2);
    }
}

int main() 
{
    printf("\nTesting\n");

    // Test Strlen
    printf("\nStrlen --> ");
    char *strlen0 = "Hola";
    char *strlen1 = "";
    char *strlen2 = "!!:)";
    char *strlen3 = "$% 43iu 5";
    test_strlen(strlen1);
    test_strlen(strlen2);
    test_strlen(strlen3);
    test_strlen(strlen0);
    
    // Test Memset
    printf("\nMemset --> ");
    char memset0[20] = "Hola !Adios";
    char memset1[20] = "";
    char memset2[20] = "      ";
    char memset3[20] = "Hola !Adios";
    test_memset(memset0, 'a', 4);
    test_memset(memset1, 'a', 0);
    test_memset(memset2, 'a', 9);
    test_memset(memset3, 'a', 0);

    // Test Memcpy
    printf("\nMemcpy --> ");
    char srcmemcpy[20] = "Hola !Adios";
    char destmemcpy[20] = "Hola !Adios";    
    test_memcpy(destmemcpy, srcmemcpy, 4);
    test_memcpy(destmemcpy, srcmemcpy, 0);    
    test_memcpy(srcmemcpy - 2, srcmemcpy, 0);
    test_memcpy(srcmemcpy + 2, srcmemcpy, 0);
    
    // Test Memmove
    printf("\nMemmove --> ");
    char srcmove0[20] = "Hola !Adios";
    char destmove0[20] = "Nos Vamos!";
    test_memmove(destmove0, srcmove0, 4);
    test_memmove(destmove0, srcmove0, 0);
    test_memmove(srcmove0 + 2, srcmove0, 4);
    test_memmove(srcmove0 - 2, srcmove0, 4);

    //Test strlcpy
    printf("\nStrlcpy --> ");
    char src0[8] = "Testing";
    char src1[8] = "Hello";
    char src3[8] = "";
    char dest0[2] = "";
    char dest1[2] = "He";
    char dest2[] = "Hello";

    test_strlcpy(src0, dest0, 2);
    test_strlcpy(src3, dest0, 0);
    test_strlcpy(src3, dest0, 1);
    test_strlcpy(src3, dest1, 2);
    test_strlcpy(src3, dest1, 3);

    test_strlcpy(src1, dest0, 0);
    
    test_strlcpy(src1, dest0, 1);
    test_strlcpy(src1, dest0, 3);
    test_strlcpy(src1, dest2, 3);
        
    
    printf("\n");
    return 0;
}
