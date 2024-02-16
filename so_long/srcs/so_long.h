/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:11:40 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/15 13:56:00 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <string.h>

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
} t_map;

char **process_map(int fd, t_map *map);
void	print_map(char **map);
int	check_map(t_map *map);

int count_rows(char **map_grid);
int count_columns(char **map_grid);

void look_for_exit(t_map *map);
void look_for_player(t_map *map);