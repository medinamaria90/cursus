/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:16:36 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/17 00:34:56 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_memory(char *str)
{
	free (str);
	str = NULL;
	return (NULL);
}

char	*ft_strdup_len(const char *s, int len)
{
	char	*str;
	int		size;	

	if (s == NULL)
		return (NULL);
	if ((len == -1) || ((int)ft_strlen(s) < len))
		size = ft_strlen(s) + 1;
	else
		size = len;
	str = (char *)malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, size);
	return (str);
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
		free(*container);
		*container = NULL;
		return (new_line);
	}
	break_line = (ft_strchr(*container, '\n') - *container) + 1;
	aux_buff = ft_strdup_len(&(*container)[break_line], -1);
	if (!aux_buff)
		return (NULL);
	new_line = ft_strdup_len((*container), break_line + 1);
	if (!new_line)
		free_memory(aux_buff);
	free (*container);
	*container = aux_buff;
	return (new_line);
}

char	*read_file(int fd, char **container)
{
	char	*buffer;
	char	*temp;
	int		bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	bytes = 1;
	buffer[0] = 0;
	while (!ft_strchr(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		//printf ("bts:%d ", bytes);
		if (bytes > 0)
		{
			//printf("Buffer is --> %s ", buffer);
			buffer[bytes] = '\0';
			//printf("Buffer is --> %s ", buffer);
			temp = ft_strjoin(*container, buffer);
			if (!temp)
				return (free_memory(buffer));
			free(*container);
			*container = temp;
		}
	}
	if (bytes == -1)
		return (free_memory(buffer));
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*container;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, &container);
	if (!buffer)
	{
		printf("buffer is null\n");
		return (free_memory(container));
	}
	if (!container)
		return (free_memory(buffer));
	line = ft_divide_line(&container);
	if (!line)
		return (free_memory(buffer));
	free (buffer);
	if (ft_strlen(line) == 0 && !container)
	{
		free(container);
		return (free_memory(line));
	}
	return (line);
}

/*
int main(void) 
{
    int file_descriptor = open("testing1.txt", O_RDONLY);
    if (file_descriptor == -1) 
	{
        perror("Error opening file");
        return 1;
    }

    char *line;
	int	line_number = 1;

    while ((line = get_next_line(file_descriptor)) != NULL//
	 && (line_number < 15)) 
	{
        printf("Line %d: %s\n", line_number, line);
        line_number++;
    }

    return (0);
}
*/
/*
	line = get_next_line(file_descriptor);
	printf("Line 1: %s\n", line);
	char *line1 = get_next_line(file_descriptor) ;
	printf("Line 2: %s\n", line1);
	char *line2 = get_next_line(file_descriptor); 
	printf("Line 3: %s\n", line2);
	char *line3 = get_next_line(file_descriptor);
	printf("Line 4: %s\n", line3);
    close(file_descriptor);
	*/