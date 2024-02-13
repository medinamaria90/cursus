/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:28:38 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/13 13:34:36 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_horizontal(char **map, int rows)
{
	int	n;

	n = 0;
	while (map[0][n])
	{
		if (map[0][n] != '1')
			return (1);
		n++;
	}
	n = 0;
	while (map[rows - 1][n])
	{
		if (map[rows - 1][n] != '1')
			return (1);
		n++;
	}
	return (0);
}

int	check_rectangle(char **map)
{
	size_t	len_row;
	int	n;

	n = 0;
	len_row = ft_strlen(map[n]);
	while (map[++n])
	{
		if (ft_strlen(map[n]) != len_row)
			return (1);
	}
	return (0);
}

int	check_map(char **map, int rows)
{
	if (check_rectangle(map) == 1 || check_horizontal(map, rows) == 1)
		return (1);
	check_map_items(map, 6, 15);
	return (0);		
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

char **process_map(int fd)
{
	char	**map;
	int		i;
	
	map = malloc(sizeof(char *));
	map[0] = get_row(fd);
	i = 0;
	while (map[i] != NULL)
	{
		i++;
		map = ft_realloc(map, sizeof(char *) * (i + 2));
		map[i] = get_row(fd);
	}
	printf("Check map: %d\n", check_map(map, i));
	print_map(map);
	return (map);
}