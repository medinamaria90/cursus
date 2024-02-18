/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:48:01 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/18 18:49:32 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(int error)
{
	write(1, "Error\n", 6);
	if (error == 1)
			write(1, "Introduce just one argument, which must be a valid map\n", 55);
	if (error == 2)
			write(1, "The map extension is not correct\n", 33);
	if (error == 3)
			write(1, "The map is empty\n", 17);
	if (error == 4)
			write(1, "Exit, coins or character not found\n", 35);
	if (error == 5)
			write(1, "The map is not a rectangle\n", 27);
	if (error == 6)
			write(1, "The walls are not closed\n", 25);
	if (error == 7)
			write(1, "There is not a valid way\n", 25);
	if (error == 8)
			write(1, "There is at least one duplicated character\n", 43);
	return (1);
}