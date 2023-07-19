/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:58:39 by wel-safa          #+#    #+#             */
/*   Updated: 2023/07/19 17:41:23 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Check if buffer has new line and return index of line
*/
int	ft_checknl(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (-1);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

/*
	return string before new line ending in new line and null
	rearrange buffer to keep everything after new line and null the rest of the buffer space.
*/
char	*ft_splitnl(char *buff, int i)
{
	int		j;
	char	*temp;
	//char	rest[ft_strlen(buff) - i + 1];

	temp = (char *)ft_calloc(sizeof(char), i + 2);
	j = 0;
	while (j <= i)
	{
		temp[j] = buff[j];
		j++;
	}
	j = 0;
	while (buff[j])
	{
		if (j > (ft_strlen(buff) - i))
			buff[j] = '\0';
		else
			buff[j] = buff[j + i + 1];
		j++;
	}
	return (temp);
}
// temp should be freed later in main function when testing

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*ptr;
	size_t	i;

	i = 0;
	size = ft_strlen(s);
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (0);
	while (i < size + 1)
	{
		((char *)ptr)[i] = ((char *)s)[i];
		i++;
	}
	return (ptr);
}

int ft_readfile(int fd, char **bufferptr)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(read(fd, buffer, BUFFER_SIZE) < 0)
	{
		free(buffer);
		return (-1);
	}
	bufferptr[0] = buffer;
	return (0);
}

/*
read(fd, 0, 0) if negative -> All contents of the file have been read or error occured
*/
char	*get_next_line(int fd)
{
	static char	*bufferptr[1];
	char		*temp;
	char		*rest;

	if (fd == -1 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// maybe for the read check, I should free buffer?
	if (!bufferptr[0]) // has not been assigned a value yet
		ft_readfile(fd, bufferptr);
	if (ft_checknl(bufferptr[0]) >= 0) // new line was found
	{
		return (ft_splitnl(bufferptr[0], ft_checknl(bufferptr[0])));
		// We have to return everything before new line.
		// and keep the rest malloced and saved in the static variable.
	}
	else
	{
		temp = ft_strdup(bufferptr[0]);
		// copy buffer to temp
		free(bufferptr[0]);
		// free buffer
		
		// malloc new buffer and assign it to bufferptr[0]
		// copy temp to new malloced buffer
		// read more file contents into temp value
		// concat temp into buffer
		// get_next_line.
		// or while(buffer has no new line in it keep reading)
	}
	//rest = ft_restcpy(bufferptr[0]);// copy buffer to rest
	// free buffer
	//buffer = (char *)ft_calloc(BUFFER_SIZE + ft_strlen(rest) + 1, 1);
	//if (!buffer)
	//	return (NULL);
	read(fd, bufferptr[0], 1);
	return (bufferptr[0]);
}
/*
int	main(void)
{
	int		fd;
	char	*filepath;
	char	*line;

	filepath = "test.txt";
	fd = open(filepath, O_RDONLY);
	//fd = 0;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
*/
