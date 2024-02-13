/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:11:40 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/13 12:27:30 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <string.h>

struct grid {
  int x;
  int y;
  char content;
};

char **process_map(int fd);
void	print_map(char **map);