/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:22:15 by marimedi          #+#    #+#             */
/*   Updated: 2023/11/30 18:40:28 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	size = ft_strlen(s);
	while (s[size] >= 0)
	{
		if (s[size] == c)
			return ((char *)(s + size));
		size--;
	}
	if (c == '\0' && s[size + 1] == '\0')
		return ((char *)(s + size));
	return (0);
}
