/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:37:58 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/07 11:37:51 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		size;
	char	*string;

	size = ft_strlen(s);
	string = (char *)malloc(sizeof(char) * size + 1);
	if (string == NULL)
		return (NULL);
	string[size--] = '\0';
	while (size >= 0)
	{
		string[size] = f(size, s[size]);
		size --;
	}
	return (string);
}
