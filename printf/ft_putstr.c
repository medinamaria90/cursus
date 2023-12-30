/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:47:30 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/23 12:08:37 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	n;

	if (str == NULL)
		return (ft_putstr("(null)"));
	n = 0;
	while (str[n])
	{
		write(1, &str[n], 1);
		n++;
	}
	return (n);
}
