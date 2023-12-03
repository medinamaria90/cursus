/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:19:47 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/01 20:40:26 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const*s1, char const *s2)
{
	char	*s3;
	size_t	lens1;
	size_t	lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	s3 = (char *)malloc(((lens1 + lens2) + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy(s3, s1, lens1 + 1);
	ft_strlcat(s3, s2, lens2 + lens1 + 1);
	return (s3);
}


