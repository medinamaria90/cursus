/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:06:29 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/21 16:04:47 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return(1);
}

int	ft_putstr(char *str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		write(1, &str[n], 1);
		n++;		
	}
	return(n);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	count;

	if (src == NULL)
		return (-1);
	count = 0;
	while (count < n - 1 && src[count] && n != 0)
	{
		if (src[count])
			dest[count] = src[count];
		else
			dest[count] = '\0';
		count ++;
	}
	if (n != 0)
		dest[count] = '\0';
	while (src[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup_len(const char *s, int len)
{
	char	*str;
	int		size;	

	if (s == NULL)
		return (NULL);
	if ((len == -1) || ((int)ft_strlen(s) < len))
		size = ft_strlen(s) + 1;
	else
		size = len;
	str = (char *)malloc(size * sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	ft_strlcpy(str, s, size);
	return (str);
}
