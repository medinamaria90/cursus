/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:28:38 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/18 18:49:53 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_map *map)
{
	int	col;
	int	row;
	int	direction;

	col = 0;
	row = 0;
	direction = 0;
	while (direction < 4)
	{
		if (map->grid[row][col] != '1')
			return (1);
		if (direction == 0)
			col++;
		else if (direction == 1)
			row++;
		else if (direction == 2)
			col--;
		else if (direction == 3)
			row--;
		if (col == 0 && (row == 0 || row == map->rows - 1) 
			|| col == map->cols - 1 && (row == 0 || row == map->rows - 1))
			direction++;
	}
	return (0);
}

int	check_if_rectangle(t_map *map)
{
	size_t	cols;
	int	row;

	if (map == NULL || map->grid == NULL || map->grid[0] == NULL)
        return (1);
	cols = ft_strlen(map->grid[0]);
	row = 1;
	while (map->grid[row])
	{
		if (ft_strlen(map->grid[row]) != cols)
			return (1);
		row++;
	}
	map->rows = row;
	map->cols = cols;
	return (0);
}

int	check_isolated_items(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (map->grid[row] != NULL)
	{
		col = 0;
		while (col < map->cols)
		{
			if (map->grid[row][col] != '1' && map->visited[row][col] != '1')
				return (1);
			col++;
		}
		row++;
	}
	return (0);
}

int	check_map(t_map *map)
{
	printf("In check map\n");
	if (check_if_rectangle(map) == 1)
		return (ft_error(5));
	printf("Just checking\n");
	if (check_walls(map) == 1)
		return (ft_error(6));
	initialize_visited(map);
	flood_fill(map, map->player);
	printf("\n");
	print_map(map->visited);
	printf("\n");
	print_map(map->grid);
	printf("\n");
	if (check_isolated_items(map) == 1)
		return (ft_error(7));
	printf("ALL IS OK =D \n");
	return (0);
}