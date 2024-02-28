/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:42:41 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/27 14:46:30 by marimedi         ###   ########.fr       */
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
	{
		ft_error(1);
		return (-1);
	}
	filename = argv[1];
	extension = ft_strrchr(filename, '.');
	if (extension == NULL)
		return (ft_error(1));
	if (ft_strncmp(extension, ".ber", ft_strlen(extension)) != 0)
	{
		ft_error(2);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_error(1);
		return (-1);
	}
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

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void mlx_draw_pixel(uint8_t* pixel, uint32_t color)
{
	*(pixel++) = (uint8_t)(color >> 24);
	*(pixel++) = (uint8_t)(color >> 16);
	*(pixel++) = (uint8_t)(color >> 8);
	*(pixel++) = (uint8_t)(color & 0xFF);
}

void	write_color(mlx_image_t** img, int width, int height, int32_t color)
{
	int32_t	y;
	int32_t	x;

	y = 0;
	printf("img width is %d\n", width);
	printf("img width is %d\n", height);
	while (y < height)
	{
		x = 0;
		while ( x < width)
		{
			mlx_draw_pixel((*img)->pixels + (y * width + x) * sizeof(int32_t), color);
			x++;
		}
		y++;
	}
}

int	create_graphics(t_map *map)
{
	//int green_color = 0x00A0BB24;
	
	//mlx_set_setting(MLX_MAXIMIZED, false);
	mlx_t* mlx = mlx_init(100 * map->cols, 100 * map->rows, "So_long", true);
	if (!mlx)
		ft_error_mlx();

	mlx_image_t* bg_img = mlx_new_image(mlx, 100 * map->cols, 100 * map->rows);
	
	write_color(&bg_img, 100 * map->cols, 100 * map->rows, get_rgba(0, 0, 255, 255));
	mlx_image_to_window(mlx, bg_img, 0, 0);

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
