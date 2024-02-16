/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:42:41 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/15 11:41:24 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int i;
	
	i = 0;
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	free_array(char **grid)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	main(void)
{
	t_map	*map;
	int		fd;

	map = malloc(sizeof(t_map));
	fd = open("map.ber", O_RDONLY);
	map->grid = process_map(fd, map);
	if (map->grid == NULL)
		return (1);
	check_map(map);
	free_array(map->grid);
	printf("last\n");
	free(map);
	return (0);
}