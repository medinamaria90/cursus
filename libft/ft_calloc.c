/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:20:45 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/01 19:16:41 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	str = (void *)malloc(size * nmemb);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size * nmemb);
	return (str);
}
