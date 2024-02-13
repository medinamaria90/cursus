/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_items.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:28:38 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/13 14:00:00 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h>
#include <string.h>

char **copy_map(char **original, int rows, int cols) 
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


void	collect_all(char **map, int row, int column, int direction)
{
	while(map[row][column] != '1')
	{
		map[row][column] = '0';
		if (direction == 'u')
			row--;
		else if (direction == 'd')
			row++;
		else if (direction == 'r')
			column++;
		else if (direction == 'l')
			column--;
	}
	print_map(map);
}

int	check_map_items(char **map, int row, int column)
{
	char	**temp_map;

	temp_map = copy_map(temp_map, row, column);
	collect_all(temp_map, row, column, 'u');
	collect_all(temp_map, row, column, 'd');
	collect_all(temp_map, row, column, 'l');
	collect_all(temp_map, row, column, 'r');
}