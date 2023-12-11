/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:14:39 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/11 11:43:22 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_trim_end(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	set_len;
	size_t	j;

	set_len = ft_strlen(set);
	s1_len = ft_strlen(s1);
	j = set_len;
	while (s1_len > 0 && set_len > 0)
	{
		while (s1[s1_len - 1] == set[set_len - 1])
		{
			s1_len--;
			set_len = j;
		}
		set_len--;
	}
	return (s1_len);
}

static size_t	ft_trim_start(char const *s1, char const *set)
{
	size_t	set_len;
	size_t	i;
	size_t	j;

	set_len = ft_strlen(set);
	i = 0;
	j = 0;
	while (s1[i] && j < set_len)
	{
		while (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	len;

	if (s1 == NULL)
		return (ft_strdup(""));
	start = ft_trim_start(s1, set);
	len = ft_trim_end(&s1[start], set);
	str = ft_substr(s1, start, len);
	if (str == NULL)
		return (NULL);
	return (str);
}
