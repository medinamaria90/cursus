/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:46:43 by marimedi          #+#    #+#             */
/*   Updated: 2023/11/07 17:46:24 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(char *str, char *to_find)
{
	int	count;
	int	aux_count;

	count = 0;
	while (str[count])
	{
		if (str[count] == to_find[0])
		{
			aux_count = 0;
			while (str[aux_count + count] == to_find[aux_count])
				aux_count++;
			if (to_find[aux_count] == '\0')
				return (str + count);
		}
		count++;
	}
	return (0);
}
