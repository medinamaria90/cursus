/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:42:41 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/20 13:22:00 by marimedi         ###   ########.fr       */
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

int	free_map(t_map *map)
{
	int	i;

	if (!map->grid)
		return (0);
	i = 0;
	while (map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	i = 0;
	while (map->visited[i])
	{
		free(map->visited[i]);
		i++;
	}
	free(map->visited);
	free(map);
	return (0);
}

int	check_arguments(int argc, char *argv[])
{
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
	return (fd);
}

static void ft_error_mlx(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;
	(void)mlx;
}

int	create_graphics(t_map *map)
{
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "So_long", true);
	if (!mlx)
		ft_error_mlx();

	/* Do stuff */

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error_mlx();

	// Even after the image is being displayed, we can still modify the buffer.
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
	(void)map;
}

int32_t	main(int32_t argc, char *argv[])
{
	t_map	*map;
	int		fd;
	
	fd = check_arguments(argc, argv);
	if (fd == -1)
		return (1);
	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (1);
	if (process_map(fd, map) == -1)
		return (free_map(map));
	if (create_graphics(map) == -1)
		return (free_map(map));
	return (free_map(map));
}
