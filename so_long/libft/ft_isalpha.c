/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.your42network>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:30:56 by marimedi          #+#    #+#             */
/*   Updated: 2023/11/29 13:01:42 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int param)
{
	if (param >= 'A' && param <= 'Z')
		return (1);
	else if (param >= 'a' && param <= 'z')
		return (2);
	return (0);
}
