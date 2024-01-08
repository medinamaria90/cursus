/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:47:30 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/08 19:13:15 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	n;
	int	written;

	if (str == NULL)
		return (ft_putstr("(null)"));
	n = 0;
	while (str[n])
	{
		written = write(1, &str[n], 1);
		if (written == -1)
			return (written);
		n++;
	}
	return (n);
}
