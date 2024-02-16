/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:28:38 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/16 18:30:58 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h>
#include <string.h>

char **copy_map(char **original, int rows) 
{
    char **copy;
	int	i;
	
	copy = (char **)malloc(rows * sizeof(char *));
	if (copy == NULL)
		return NULL;
	i = 0;
	while (i < rows)
	{
        copy[i] = strdup(original[i]);
        if (copy[i] == NULL) 
		{
			i = 0;
			while (copy[i])
                free(copy[i++]);
            free(copy);
            return NULL;
        }
		i++;
    }
    return copy;
}




int	check_horizontal_walls(t_map *map)
{
	int	n;

	n = 0;
	while (map->grid[0][n])
	{
		if (map->grid[0][n] != '1')
			return (1);
		n++;
	}
	n = 0;
	while (map->grid[map->rows - 1][n])
	{
		if (map->grid[map->rows - 1][n] != '1')
		{
			printf("Not horizontal walls\n");
			return (1);
		}
		n++;
	}
	return (0);
}

int	check_rectangle(t_map *map)
{
	size_t	cols;
	int	row;

	cols = ft_strlen(map->grid[0]);
	row = 1;
	while (map->grid[row])
	{
		if (ft_strlen(map->grid[row]) != cols)
		{
			printf("Not a rectangle\n");
			return (1);
		}
		row++;
	}
	map->rows = row;
	map->cols = cols;
	return (0);
}

void	go_every_pos(t_map *map)
{
	printf("Go to every pos");
	map->visited[map->player.col][map->player.row] = '1';
	if (map->grid[map->player.row++][map->player.col] != '1')
		map->visited[map->player.col][map->player.row] = '1';	
	if (map->grid[map->player.row--][map->player.col] != '1')
		map->visited[map->player.col][map->player.row] = '1';	
	if (map->grid[map->player.col++][map->player.col] != '1')
		map->visited[map->player.col][map->player.row] = '1';	
	if (map->grid[map->player.col++][map->player.col] != '1')
		map->visited[map->player.col][map->player.row] = '1';
}
int	get_new_pos(t_map *map, t_pos *player)
{
	if (map->visited[player->row][player->col] == '1')
	{
		printf("Already visited\n");
		return (0);	
	}
	map->visited[player->row][player->col] = '1';
	if (map->grid[player->row + 1][player->col] != '1' && map->visited[player->row + 1][player->col] != '1')
	{
		printf("current box content --> %c\n", map->grid[player->row][player->col]);
		printf("next box content --> %c\n", map->grid[player->row + 1][player->col]);
		player->row++;
		printf("Go down\n");
	}
	else if (map->grid[player->row - 1][player->col] != '1' && map->visited[player->row - 1][player->col] != '1')
	{
		printf("current box visited --> %c\n", map->visited[player->row][player->col]);
		printf("next box visited --> %c\n", map->visited[player->row - 1][player->col]);
		printf("Go up\n");
		player->row--;
	}
	else if (map->grid[player->row][player->col + 1] != '1' && map->visited[player->row][player->col + 1] != '1')
	{
		printf("next box content --> %c\n", map->grid[player->row][player->col + 1]);
		printf("Go right\n");
		player->col++;
	}
	else if (map->grid[player->row][player->col - 1] != '1' && map->visited[player->row][player->col -1] != '1')
	{
		printf("Go left \n");
		player->col--;
	}
	else
	{
		printf("No more movements\n");
		return (0);
	}
	
	return (1);
}

int walk_around(t_map *map, t_pos player) 
{
	t_pos	player_cpy;
	int		new_pos;
	
	player_cpy.row = map->player.row;
	player_cpy.col = map->player.col;
	printf("player pos: row %d col %d\n", player.row, player.col);
	while (get_new_pos(map, &player) == 1)
	{
		walk_around(map, player);
		printf("\nplayer NEW pos: row %d col %d\n", player.row, player.col);
		new_pos = get_new_pos(map, &player);
	}
	return (0);
}

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


int	check_map(t_map *map)
{
	if (check_rectangle(map) == 1)
		return (1);
	if (check_horizontal_walls(map) == 1)
		return (1);
	initialize_visited(map);
	walk_around(map, map->player);
	print_map(map->visited);
	return (0);
}