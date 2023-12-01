/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:54:50 by marimedi          #+#    #+#             */
/*   Updated: 2023/11/07 17:34:30 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	count;

	count = 0;
	while ((s1[count] || s2[count]) && n > count)
	{
		if ((unsigned char)s1[count] > (unsigned char)s2[count])
			return (1);
		else if ((unsigned char)s1[count] < (unsigned char)s2[count])
			return (-1);
		count ++;
	}
	return (0);
}
