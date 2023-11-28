/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.your42network>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:31:21 by marimedi          #+#    #+#             */
/*   Updated: 2023/11/28 10:31:24 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isdigit(int param)
{
	if (param >= '0' && param <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d",isdigit('6'));
}
*/
