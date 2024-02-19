/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:28:38 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/19 13:20:00 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	forbidden_chars(t_map *map)
{
	int		col;
	int		row;
	char	allowed_chars[6];

	row = 0;
	while (map->grid[row])
	{
		col = 0;
		while(map->grid[row][col])
		{
			if (!ft_strchr(allowed_chars, map->grid[row][col]))
				return (1);
			col++;
		}
		row++;
	}
	return (0);
}

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
		if ((col == 0 && (row == 0 || row == map->rows - 1)) 
			|| (col == map->cols - 1 && (row == 0 || row == map->rows - 1)))
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
	if (check_if_rectangle(map) == 1)
		return (ft_error(5));
	if (check_walls(map) == 1)
		return (ft_error(6));
	if (forbidden_chars(map) == 1)
		return (ft_error(9));
	initialize_visited(map);
	flood_fill(map, map->player);
	if (check_isolated_items(map) == 1)
		return (ft_error(7));
	printf("Map is correct\n");
	return (0);
}