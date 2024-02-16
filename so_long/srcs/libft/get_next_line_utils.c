/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:01:45 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/15 09:59:45 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*s3;
	size_t	lens1;
	size_t	lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	s3 = (char *)malloc(((lens1 + lens2) + 1) * sizeof(char));
	if (!s3)
	{
		free((void *)(s1));
		return (NULL);
	}
	ft_strlcpy(s3, s1, lens1 + 1);
	ft_strlcpy(s3 + lens1, s2, lens2 + 1);
	if (s1)
		free((void *)(s1));
	return (s3);
}
