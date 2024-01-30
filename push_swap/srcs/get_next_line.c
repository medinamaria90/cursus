/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:16:36 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/20 14:25:55 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_memory(char **str)
{
	if (*str)
		free (*str);
	*str = NULL;
	return (NULL);
}

char	*ft_divide_line(char **container)
{
	char	*aux_buff;
	char	*new_line;
	size_t	break_line;

	if (ft_strchr(*container, '\n') == NULL)
	{
		new_line = ft_strdup_len(*container, -1);
		if (!new_line)
			return (NULL);
		if (*container)
			free_memory(container);
		return (new_line);
	}
	break_line = (ft_strchr(*container, '\n') - *container) + 1;
	aux_buff = ft_strdup_len(&(*container)[break_line], -1);
	if (!aux_buff)
		return (NULL);
	new_line = ft_strdup_len((*container), break_line + 1);
	if (!new_line)
		return (free_memory(&aux_buff));
	if (*container)
		free_memory(container);
	*container = aux_buff;
	return (new_line);
}

char	*read_file(int fd, char **container)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (free_memory(&buffer));
	bytes = 1;
	buffer[0] = 0;
	while (!ft_strchr(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free_memory(&buffer));
		buffer[bytes] = '\0';
		*container = ft_strjoin(*container, buffer);
		if (!*container)
			return (free_memory(&buffer));
	}
	free_memory(&buffer);
	return (*container);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*container;

	if (fd < 0 || BUFFER_SIZE < 1 || (read(fd, NULL, 0) < 0))
	{
		if (container)
			return (free_memory(&container));
		container = NULL;
		return (NULL);
	}
	if (read_file(fd, &container) == NULL)
		return (free_memory(&container));
	if (!container)
		return (NULL);
	line = ft_divide_line(&container);
	if (!line)
		return (free_memory(&container));
	if (ft_strlen(line) == 0 && !container)
		return (free_memory(&line));
	return (line);
}
