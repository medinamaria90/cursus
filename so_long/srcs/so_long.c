/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:42:41 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/19 10:36:30 by marimedi         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_map	*map;
	char	*filename;
	int		fd;
	char	*extension;
	
	if (argc != 2)
		return (ft_error(1));
	filename = argv[1];
	extension = ft_strrchr(filename, '.');
	if (extension == NULL)
		return (ft_error(1));
	if (ft_strncmp(extension, ".ber", ft_strlen(extension)) != 0)
		return(ft_error(2));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(1));
	map = malloc(sizeof(t_map));
	if (process_map(fd, map) == -1)
		return (1);
	//free_array(map->grid);
	//free(map);
	return (0);
}
