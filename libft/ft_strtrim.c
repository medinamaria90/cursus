/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:14:39 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/01 21:29:26 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	slen;
	size_t	set_len;
	char	*tempstr;
	char	*str;

	slen = ft_strlen(s1);
	set_len = ft_strlen(set);
	if (s1 == NULL)
		return (ft_strdup(""));
	while (ft_strnstr(s1, set, set_len) != s1 && 0)
		s1 = ft_strnstr(s1, set, set_len);
	tempstr = ft_strnstr(s1, set, slen);
	slen = slen - ft_strlen(tempstr);
	str = (char *)malloc((slen + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, slen);
	if (str == NULL)
		return (NULL);
	return (str);
}
