/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:46:36 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/09 11:43:06 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	count_elements(t_stack *stack)
{
	int		count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	ft_strncmp(char const *s1, const char *s2, unsigned int n)
{
	unsigned int	count;

	count = 0;
	while ((s1[count] || s2[count]) && n > count)
	{
		if ((unsigned char)s1[count] != (unsigned char)s2[count])
			return ((unsigned char)s1[count] - (unsigned char)s2[count]);
		count ++;
	}
	return (0);
}

size_t	ft_strlcpy2(char *dest, const char *src, size_t n)
{
	size_t	count;

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
	while (src[count])
	{
		count++;
	}
	return (count);
}

size_t	ft_strlen2(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	slen;

	slen = ft_strlen2(s);
	if (s == NULL)
		return (NULL);
	if ((slen - start) < len)
		len = slen - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy2(substr, &s[start], len + 1);
	return (substr);
}
