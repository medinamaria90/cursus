/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.your42network>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:30:09 by marimedi          #+#    #+#             */
/*   Updated: 2023/11/28 10:48:29 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isalnum(int param)
{
	if ((param >= 'A' && param <= 'Z') || (param >= 'a' && param <= 'z')
		|| (param >= '0' && param <= '9'))
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d",isalnum('6'));
}
*/
