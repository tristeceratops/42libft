/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:01:59 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/26 11:02:47 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_line_null(char **remainder, char **line)
{
	*line = ft_strdup(*remainder);
	if (!(*line))
		return (NULL);
	free(*remainder);
	*remainder = NULL;
	return (*line);
}

char	*loop(char *remainder[1024], char *buffer, int fd)
{
	int	bytes_read;

	bytes_read = 1;
	while (!has_newline(remainder[fd]) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		remainder[fd] = ft_strjoin(remainder[fd], buffer);
	}
	if (bytes_read == 0 && !remainder[fd])
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*remainder[1024];
	char		*buffer;
	char		*line;

	if (fd < 0 || fd >= 1024)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!remainder[fd])
		remainder[fd] = NULL;
	buffer = loop(remainder, buffer, fd);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	line = get_line(&remainder[fd]);
	return (line);
}
/*
int	main(void)
{
	int	fd = open("b.txt", O_RDONLY);
	int	fd2 = open("test.txt", O_RDONLY);
	char	*buffer;

	buffer = get_next_line(fd);
	printf("%s", buffer); free(buffer);
	buffer = get_next_line(fd2);
        printf("%s", buffer); free(buffer);
	buffer = get_next_line(fd);
        printf("%s", buffer); free(buffer);
	buffer = get_next_line(fd2);
        printf("%s", buffer); free(buffer);
	buffer = get_next_line(fd);
        printf("%s", buffer); free(buffer);
	buffer = get_next_line(fd2);
        printf("%s", buffer); free(buffer);
	close(fd);
	close(fd2);
}*/
