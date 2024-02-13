/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:01:45 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/12 11:05:04 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_len(const char *s, int len)
{
	char	*str;
	int		size;	

	if (s == NULL)
		return (NULL);
	if ((len == -1) || ((int)ft_strlen_gnl(s) < len))
		size = ft_strlen_gnl(s) + 1;
	else
		size = len;
	str = (char *)malloc(size * sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	ft_strlcpy_gnl(str, s, size);
	return (str);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(&s[i]));
	return (NULL);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy_gnl(char *dest, const char *src, size_t n)
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

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*s3;
	size_t	lens1;
	size_t	lens2;

	lens1 = ft_strlen_gnl(s1);
	lens2 = ft_strlen_gnl(s2);
	s3 = (char *)malloc(((lens1 + lens2) + 1) * sizeof(char));
	if (!s3)
	{
		free((void *)(s1));
		return (NULL);
	}
	ft_strlcpy_gnl(s3, s1, lens1 + 1);
	ft_strlcpy_gnl(s3 + lens1, s2, lens2 + 1);
	if (s1)
		free((void *)(s1));
	return (s3);
}
