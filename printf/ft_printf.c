/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:37:50 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/21 18:58:06 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_count_elements(char const *str)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while(str[i])
	{
		if (str[i] == '%')
			count++;
		i++;
	}
	return (count);
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
		bytes = ft_putptr(va_arg(args, void *));
	if (c == 'd' || c == 'i')
		bytes = ft_putnbr(va_arg(args, int));
	if (c == 'u')
		bytes = ft_putfloat(va_arg(args, float*));
	return (bytes);
}

int	take_str(char const *str, int *next_word, int i, va_list args)
{
	char	*toprint;
	int	bytes;

	toprint = ft_strdup_len(&str[*next_word], i + 1 - *next_word);
	if (toprint == NULL)
		return (-1);
	bytes = ft_putstr(toprint) + take_arg(str[i + 1], args);
	*next_word = i + 2;
	free(toprint);
	return (bytes);
}


int	ft_printf(char const *str, ...)
{
	int i;
	int next_word;
	va_list	args;
	int	bytes;

	va_start(args, str);
	i = 0;
	next_word  = 0;
	bytes = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			bytes += take_str(str, &next_word, i, args);
			if (bytes == -1)
				return (-1);
		}
		i++;
	}
	bytes += take_str(str, &next_word, i, args);
	va_end(args);
	return (bytes);
}

int	main(void)
{
	char *str = "soy";
	char *str2 = "Maria";
	char char1 = 'M';
	char char2 = 'C';


	int bytes = ft_printf("Hola %s %s y tu\n", str, str2);
	printf("Bytes --> %d\n", bytes);	
	bytes = ft_printf("Mi Iniciales son %c y %c =)\n", char1, char2);
	printf("Bytes --> %d\n", bytes);
	bytes = ft_printf("Mis dias vividos son %i días\n", 12345678);
	printf("Bytes --> %d\n", bytes);
	bytes = ft_printf("Mis dias vividos son %d días\n", 12345678);
	printf("Bytes --> %d\n", bytes);
	bytes = printf("El puntero esta en %p\n", &char1);
	printf("Bytes --> %d\n", bytes);
	bytes = ft_printf("El puntero esta en %p\n", &char1);
	printf("Bytes --> %d\n", bytes);



	return (1);
}