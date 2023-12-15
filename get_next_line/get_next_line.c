/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:16:36 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/15 16:11:29 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <string.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	size;

	size = ft_strlen(s) + 1;
	str = (char *)malloc(size * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, size);
	return (str);
}

char *ft_divide_line(char **old_buffer)
{
	char		*aux_buff;
	char		*new_line;
	size_t		new_line_pos;
	size_t		buff_len;
	size_t		old_buffer_len;
	
	buff_len = ft_strlen(*old_buffer);
	if (buff_len == 0)
		return (0);
	new_line_pos = ft_strchr(*old_buffer, '\n') - *old_buffer;
 	if (new_line_pos > buff_len) 
    	return(NULL);
	else
	{
		new_line = (char *)malloc(sizeof(char) * (new_line_pos) + 1);
		ft_strlcpy(new_line, (*old_buffer), new_line_pos + 1); 
		old_buffer_len = ft_strlen(&(*old_buffer)[new_line_pos + 1]);
		aux_buff = (char *)malloc(sizeof(char) * (old_buffer_len + 1));
		ft_strlcpy(aux_buff, &(*old_buffer)[new_line_pos + 1], old_buffer_len + 1);
		free (*old_buffer);
		*old_buffer = (char *)malloc(sizeof(char) * (old_buffer_len + 1));
		ft_strlcpy(*old_buffer, aux_buff, old_buffer_len + 1);
		//printf("Temp buff %s\n", *old_buffer);
		free (aux_buff);
		return (new_line);
	}
	return (NULL);
}

char *ft_read_line(char *buffer, int bytes, char **old_buffer)
{
	char		*line;
	char		*new_buffer;
	char		*joint_buffer;
	size_t		old_buffer_size;
	static	int	written;
	//printf("at the beggining of read line\n");
	//printf("Beg Buffer -- %s\nBeg Old Buffer -- %s\n", buffer, *old_buffer);
	old_buffer_size = ft_strlen(*old_buffer);
	if (bytes == 0)
	{
		if (written == 0)
			return (NULL);
		if (old_buffer_size == 0)
			return (ft_strdup(""));
		return(strdup(*old_buffer));
	}
	written = 1;
	new_buffer = (char *)malloc(sizeof(char) * (bytes + 1));
	ft_strlcpy(new_buffer, buffer, bytes + 1);
	if (old_buffer_size > 0)
	{
		joint_buffer = ft_strjoin((char const *)*old_buffer, (char const *)new_buffer);
		free(*old_buffer);
		*old_buffer = ft_strdup(joint_buffer); 
		free(joint_buffer);
	}
	else
	{
		*old_buffer = ft_strdup(new_buffer);
		free(new_buffer);
	}
	//printf("AFTER Old Buffer -- %s\n", *old_buffer);
	if (ft_strchr(*old_buffer, '\n'))
	{
		line = ft_divide_line(old_buffer);	
		//printf("YESS NEW LINE -- %s\n", line);
		//printf("Old buffer is -- %s\n", *old_buffer);

		return(line);
	}
	return(NULL);
}

char *ft_read_file(int fd, char *buffer, size_t buff_size)
{
	int	bytes_read;
	static int	end_of_file;
	char	*line;
	static char	*old_buffer;

	if (end_of_file == 1)
	{
		return(NULL);
	}
	//printf("Before the line\n");
	line = ft_divide_line(&old_buffer);
	if (line != NULL)
		return (line);
	bytes_read = 1;
	//printf("Buffer is --> %s\n", buffer);
	while ((bytes_read = read(fd, buffer, buff_size)) > 0)
	{
		//bytes_read = read(fd, buffer, buff_size);
		//printf("The buffer is %s\n", buffer);
		//printf("The old buffer is %s\n", old_buffer);
		//printf("Bytes read are %i\n", bytes_read);
		if (bytes_read == -1)
		{
			free(old_buffer); 
			//printf("bytes read were -1\n");
			return (NULL);
		}
		if (ft_strchr(buffer, '\n'))
		{
			line = ft_read_line(buffer, bytes_read, &old_buffer);
			//printf("buffer and bytes read %s, %d\n", buffer, bytes_read);
			//memset((void *)buffer, 0, bytes_read);
			return(line);
		}
		line = ft_read_line(buffer, bytes_read, &old_buffer);
		//printf("Line is %s\n", line);
		if (line != NULL)
			return(line);
		//printf("buffer is %s\n", buffer);
		//memset((void *)buffer, 0, bytes_read);
	}
	if (bytes_read == 0)
	{
		//printf("temp buff is %s", old_buffer);
		//printf("bytes read == 0\n");
		/*
		line = malloc(sizeof(char) * (ft_strlen(old_buffer) + 1));
		if (line == NULL)
			free(old_buffer);
		ft_strlcpy(line, old_buffer, (ft_strlen(old_buffer) + 1));
		
		*/
		line = ft_read_line(buffer, 0, &old_buffer);
		free(old_buffer);
		end_of_file = 1;
		return (line);
	}
	return (line);
}

char *get_next_line(int fd)
{
	char	*buffer;
	size_t	buff_size;
	char	*line;
	
	if (fd == -1)
		return (NULL);
    #ifdef BUFFER_SIZE
        buff_size = BUFFER_SIZE;
    #else
        buff_size = DEFAULT_BUFFER_SIZE;
    #endif
	buffer = (char *)malloc(sizeof(char) * (buff_size + 1));
	buffer[0] = 0;
	if (buffer == NULL)
		return (NULL);
	//printf("Buffer before sending is -> %s\n", buffer);
	line = ft_read_file(fd, buffer, buff_size);
	//printf("line is %s\n", line);
	free(buffer);
	return (line);
}
/*
int main(void) 
{
    int file_descriptor = open("testing_1_char.txt", O_RDONLY);
    if (file_descriptor == -1) 
	{
        perror("Error opening file");
        return 1;
    }

    char *line;
	int	line_number = 0;

    // Read lines until the end of the file
    while ((line = get_next_line(file_descriptor)) != NULL) 
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