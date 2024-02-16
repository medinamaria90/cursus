/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:28:38 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/15 13:42:25 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void look_for_player(t_map *map)
{
	int row;

	row = 0;
	while (map->grid[row])
	{
		if (!ft_strchr(map->grid[row], 'P'))
			row++;
		else
		{
			map->player.row = row;
			map->player.col = ft_strchr(map->grid[row], 'P') - map->grid[row];;
			return ;
		}
	}
}

void look_for_exit(t_map *map)
{
	int row;

	row = 0;
	while (map->grid[row])
	{
		if (!ft_strchr(map->grid[row], 'E'))
			row++;
		else
		{
			map->exit.row = row;
			map->exit.col = ft_strchr(map->grid[row], 'E') - map->grid[row];
			return ;
		}
	}
}

char *get_row(int fd)
{
	char 	*line;
	char 	*new_line;
	int		new_line_size;
	
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	new_line_size = ft_strlen(line);
	if (line[new_line_size - 1] == '\n')
		new_line_size--;
	new_line = malloc(new_line_size * sizeof(char) + 1);
	if (new_line == NULL)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy(new_line, line, new_line_size + 1);
	free(line);
	return (new_line);
}



char **process_map(int fd, t_map *map)
{
	int		i;
	int		lines;

	i = 0;
	map->grid = malloc(sizeof(char *));
	if (map->grid == NULL)
		return (NULL);
	lines = 0;
	map->grid[lines] = get_row(fd);
	while (map->grid[lines])
	{	
		lines++;
		map->grid = realloc(map->grid, (lines + 1) * sizeof(char *) + 1);
		if (map->grid == NULL)
			return (NULL);
		map->grid[lines] = get_row(fd);
	}
	look_for_player(map);
	look_for_exit(map);
	printf("\n");
	print_map(map->grid);
	printf("\n");
	return (map->grid);
}