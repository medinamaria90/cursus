/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:40:46 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/15 11:41:55 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	count_rows(char **map_grid)
{
	int	rows;

	if (map_grid == NULL)
		return (0);
	rows = 0;
	while (map_grid[rows] != NULL)
		rows++;
	return (rows);
}
int	count_columns(char **map_grid)
{
	int	col;

	if (map_grid == NULL)
		return (1);
	col = 0;
	while (map_grid[0][col] != '\0')
		col++;
	return (col);
}