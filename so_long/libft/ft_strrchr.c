/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:22:15 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/01 11:28:01 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	size = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[size]);
	while (size >= 0)
	{
		if (s[size] == (char)c)
			return ((char *)&s[size]);
		size--;
	}
	return (NULL);
}
