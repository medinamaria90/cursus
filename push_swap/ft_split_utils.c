/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:46:36 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/25 15:58:34 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
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

size_t	ft_strlen(const char *str)
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

	slen = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if ((slen - start) < len)
		len = slen - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, &s[start], len + 1);
	return (substr);
}