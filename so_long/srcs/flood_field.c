/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:34:59 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/18 16:41:18 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initialize_visited(t_map *map)
{
	int	row;
	int col;
	map->visited = malloc(map->rows * sizeof(char *));
	if (map->visited == NULL)
		return(1);
	row = 0;
	while (row < map->rows)
	{
		map->visited[row] = malloc((map->cols) * sizeof(char));
		col = 0;
		while(col < map->cols)
		{
			map->visited[row][col] = '0';
			col++;
		}
		map->visited[row][col] = 0;
		row++;
	}
	map->visited[++row] = NULL;
	return (0);
}

t_pos	move_player(t_map *map, int direction, t_pos player)
{
	t_pos	new_player;

	new_player = player;
	map->visited[player.row][player.col] = '1';
	if (direction == 1)
	{
		map->visited[player.row + 1][player.col] = '1';
		new_player.row++;
	}
	else if (direction == 2)
	{
		map->visited[player.row - 1][player.col] = '1';
		new_player.row--;
	}
	else if (direction == 3)
	{
		map->visited[player.row][player.col + 1] = '1';
		new_player.col++;
	}
	else if (direction == 4)
	{
		map->visited[player.row][player.col - 1] = '1';
		new_player.col--;
	}
	return (new_player);
}

int	direction_to_move(t_map *map, t_pos *player)
{
	int way;

	way = 0;
	if (map->grid[player->row + 1][player->col] != '1' && map->visited[player->row + 1][player->col] != '1')
		way = 1;
	else if (map->grid[player->row - 1][player->col] != '1' && map->visited[player->row - 1][player->col] != '1')
		way = 2;
	else if (map->grid[player->row][player->col + 1] != '1' && map->visited[player->row][player->col + 1] != '1')
		way = 3;
	else if (map->grid[player->row][player->col - 1] != '1' && map->visited[player->row][player->col -1] != '1')
		way = 4;
	return way;
}

int	flood_fill(t_map *map, t_pos player) 
{
	t_map	*map_cpy;
	int		direction;
	int		new_pos;
	t_pos	new_player;

	direction = direction_to_move(map, &player);
	while (direction > 0)
	{
		new_player = move_player(map, direction, player);
		flood_fill(map, new_player);
		direction = direction_to_move(map, &player);
	}
	return (0);
}