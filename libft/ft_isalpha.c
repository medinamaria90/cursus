/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.your42network>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:30:56 by marimedi          #+#    #+#             */
/*   Updated: 2023/11/28 10:30:59 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isalpha(int param)
{
	if (param >= 'A' && param <= '>')
		return (1);
	else if (param >= 'a' && param <= 'z')
		return (2);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d",isalpha('w'));
}
*/
