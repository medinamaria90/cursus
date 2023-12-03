/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:14:39 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/03 19:06:25 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trim_end(char *s1, char const *set)
{
	size_t	s1_len;
	size_t	set_len;
	size_t	i;
	size_t	j;

	set_len = ft_strlen(set);
	s1_len = ft_strlen(s1);
	i = s1_len;
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
	if (i != s1_len)
		ft_bzero(&s1[s1_len], i - s1_len);
	return (s1);
}

static char	*ft_trim_start(char const *s1, char const *set)
{
	size_t	set_len;
	size_t	i;
	size_t	j;
	char	*str;

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
	str = ft_strdup(&s1[i]);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tempstr;
	char	*str;

	if (s1 == NULL)
		return (ft_strdup(""));
	tempstr = ft_trim_start(s1, set);
	if (tempstr == NULL)
		return (NULL);
	ft_trim_end(tempstr, set);
	str = ft_strdup(tempstr);
	if (str == NULL)
		return (NULL);
	free(tempstr);
	return (str);
}
