/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:11:40 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/18 18:46:00 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_pos{
  int row;
  int col;
} t_pos;

typedef struct s_map{
  int rows;
  int cols;
  char **grid;
  char  **visited;
  t_pos player;
  t_pos exit;
  int   coins;
  int   col_coins;
} t_map;

int	process_map(int fd, t_map *map);
void	print_map(char **map);
int	check_map(t_map *map);

int count_rows(char **map_grid);
int count_columns(char **map_grid);

int	flood_fill(t_map *map, t_pos player);
int	initialize_visited(t_map *map);

int	ft_error(int error);