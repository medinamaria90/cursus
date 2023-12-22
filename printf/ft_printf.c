/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:37:50 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/22 17:12:51 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

int	ft_hex_converting(int n, int sign)
{
	int bytes;

	bytes = ft_int_to_hex(n, sign, 1);
	return (bytes);
}

int	take_arg(char c, va_list args)
{
	int	bytes;

	bytes = 0;
	if (c == 'c')
		bytes = ft_putchar(va_arg(args, int));
	if (c == 's')
		bytes = ft_putstr(va_arg(args, char *));
	if (c == 'p')
		bytes = ft_putstr("0x") + ft_int_to_hex(va_arg(args, uintptr_t), 0, 0);
	if (c == 'd' || c == 'i')
		bytes = ft_putnbr(va_arg(args, int));
	if (c == 'u')
		bytes = ft_putnbr_big(va_arg(args, unsigned int));
	if (c == 'x')
		bytes = ft_hex_converting(va_arg(args, unsigned int), 0);
	if (c == 'X')
		bytes = ft_hex_converting(va_arg(args, unsigned int), 1);
	if (c == '%')
		bytes = ft_putchar('%');
	return (bytes);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		next_word;
	va_list	args;
	int		bytes;

	va_start(args, str);
	i = 0;
	next_word = 0;
	bytes = 0;
	while (str[i])
	{
		if (str[i] != '%')
			bytes += ft_putchar(str[i]);
		if (str[i] == '%')
		{
			bytes += take_arg(str[i + 1], args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (bytes);
}

/*
#include <limits.h>

int	main(void)
{
	char *str = "soy";
	char *str2 = "Maria";
	char char1 = 'M';
	//char char2 = 'C';
	int	bytes;

	printf("Test1 \n");
	bytes = printf("Hola %s %s, adios\n", str, str2);
	printf("Bytes --> %d\n", bytes);	
	bytes = ft_printf("Hola %s %s, adios\n", str, str2);
	printf("Bytes --> %d\n", bytes);

	printf("Test2 \n");
	bytes = printf("La letra es %c\n", '0' - 256);
	printf("Bytes --> %d\n", bytes);	
	bytes = ft_printf("La letra es %c\n", '0' - 256);
	printf("Bytes --> %d\n", bytes);

	printf("Test3 \n");
	bytes = printf("Mis dias vividos son %i días\n", 12345678);
	printf("Bytes --> %d\n", bytes);
	bytes = ft_printf("Mis dias vividos son %d días\n", 12345678);
	printf("Bytes --> %d\n", bytes);

	printf("Test4 \n");
	bytes = printf("El puntero esta en %p\n", &char1);
	printf("Bytes --> %d\n", bytes);
	bytes = ft_printf("El puntero esta en %p\n", &char1);
	printf("Bytes --> %d\n", bytes);

	printf("Test5 \n");
	bytes = printf("El unsigned int es %u\n", (unsigned int)INT_MAX);
	printf("Bytes --> %d\n", bytes);
	bytes = ft_printf("El unsigned int es %u\n", (unsigned int)INT_MAX);
	printf("Bytes --> %d\n", bytes);

	printf("Test6 \n");
	bytes = printf("Un hexadecimal es %x\n", 1234);
	printf("Bytes --> %d\n", bytes);
	bytes = ft_printf("Un hexadecimal es %x\n", 1234);
	printf("Bytes --> %d\n", bytes);

	printf("Test7 \n");
	bytes = printf("Un hexadecimal MAYUS es %X\n", 1234);
	printf("Bytes --> %d\n", bytes);
	bytes = ft_printf("Un hexadecimal MAYUS es %X\n", 1234);
	printf("Bytes --> %d\n", bytes);

	printf("Test8 \n");
	printf("Doble porcentaje %% \n");
	ft_printf("Doble porcentaje %% \n");

	printf("Test9 \n");
	bytes = printf(" NULL %s NULL \n", NULL);
	printf("Bytes --> %d\n", bytes);
	bytes = ft_printf(" NULL %s NULL \n", NULL);
	printf("Bytes --> %d\n", bytes);

	printf("Test10 \n");
	bytes = printf("Ptr: %p\n", (void *)-1);
	printf("Bytes --> %d\n", bytes);
	bytes = ft_printf("Ptr: %p\n", (void *)-1);
	printf("Bytes --> %d\n", bytes);

	printf("Test11 \n");
	printf("%pp%p%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	ft_printf("%pp%p%p\n",(void *)LONG_MAX + 423856,(void *)0,(void *)INT_MAX);

	printf("Testing 12.0 --> -1\n");
	printf("-1 is %x\n", -1);
	ft_printf("-1 is %x\n", -1);

	printf("Testing 12.0 --> 1\n");
	printf("-1 is %x\n", INT_MAX - 1);
	ft_printf("-1 is %x\n", INT_MAX - 1);

	printf("Test12.1 --> %li \n", LONG_MAX);
	printf(" The num is %x \n", LONG_MAX);
	ft_printf(" The num is %x\n", LONG_MAX);

	printf("Test12.3 \n");
	printf(" The num is %x \n", LONG_MIN);
	ft_printf(" The num is %x\n", LONG_MIN);

	printf("Bts - Test13 \n");
	printf("Bts - %d\n", printf(" Ptr %p str %s int %d hex %x\n", &char1, str, 2, -881234));
	ft_printf("Bts - %d\n", ft_printf(" Ptr %p str %s int %d hex %x\n", &char1, str, 2, -881234));

	return (1);
}

*/