/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:48:01 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/19 13:31:02 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(int error)
{
	write(1, "Error\n", 6);
	if (error == 1)
			write(1, "Introduce just one argument, which must be a valid map\n", 55);
	if (error == 2)
			write(1, "Map extension incorrect\n", 24);
	if (error == 3)
			write(1, "Map is empty\n", 13);
	if (error == 4)
			write(1, "Exit, coins or character not found\n", 35);
	if (error == 5)
			write(1, "The map is not a rectangle\n", 27);
	if (error == 6)
			write(1, "The walls are not closed\n", 25);
	if (error == 7)
			write(1, "Not a valid way\n", 16);
	if (error == 8)
			write(1, "Duplicated character\n", 21);
	if (error == 9)
			write(1, "Not recognizable character\n", 27);
	return (1);
}