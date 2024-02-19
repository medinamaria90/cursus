/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:34:59 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/19 11:29:19 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initialize_visited(t_map *map)
{
	int	row;
	int col;
	map->visited = malloc((map->rows + 1) * sizeof(char *));
	if (map->visited == NULL)
		return(1);
	row = 0;
	while (row < map->rows)
	{
		map->visited[row] = malloc((map->cols + 1) * sizeof(char));
		col = 0;
		while(col < map->cols)
		{
			map->visited[row][col] = '0';
			col++;
		}
		map->visited[row][col] = '\0';
		row++;
		map->visited[row] = NULL;
	}
	return (0);
}

t_pos	move_player(t_map *map, int direction, t_pos pos)
{
	t_pos	new_pos;

	new_pos = pos;
	map->visited[pos.row][pos.col] = '1';
	if (direction == 1)
	{
		map->visited[pos.row + 1][pos.col] = '1';
		new_pos.row++;
	}
	else if (direction == 2)
	{
		map->visited[pos.row - 1][pos.col] = '1';
		new_pos.row--;
	}
	else if (direction == 3)
	{
		map->visited[pos.row][pos.col + 1] = '1';
		new_pos.col++;
	}
	else if (direction == 4)
	{
		map->visited[pos.row][pos.col - 1] = '1';
		new_pos.col--;
	}
	return (new_pos);
}

int	direction_to_move(t_map *map, t_pos *pos)
{
	int way;

	way = 0;
	if (map->grid[pos->row + 1][pos->col] != '1' && map->visited[pos->row + 1][pos->col] != '1')
		way = 1;
	else if (map->grid[pos->row - 1][pos->col] != '1' && map->visited[pos->row - 1][pos->col] != '1')
		way = 2;
	else if (map->grid[pos->row][pos->col + 1] != '1' && map->visited[pos->row][pos->col + 1] != '1')
		way = 3;
	else if (map->grid[pos->row][pos->col - 1] != '1' && map->visited[pos->row][pos->col -1] != '1')
		way = 4;
	return way;
}

int	flood_fill(t_map *map, t_pos pos) 
{
	int		direction;
	t_pos	new_pos;

	direction = direction_to_move(map, &pos);
	while (direction > 0)
	{
		new_pos = move_player(map, direction, pos);
		flood_fill(map, new_pos);
		direction = direction_to_move(map, &pos);
	}
	return (0);
}