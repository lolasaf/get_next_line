/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:58:39 by wel-safa          #+#    #+#             */
/*   Updated: 2023/07/31 18:40:26 by wel-safa         ###   ########.fr       */
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
	if (!buffer || ft_strlen(buffer) == 0)
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
	returns string before new line ending in new line and null
	rearranges buffer to keep everything after new line and 
	nulls the rest of the buffer space.
*/
char	*ft_splitnl(char *buff, int i)
{
	int		j;
	char	*temp;

	if (!buff || ft_strlen(buff) == 0)
		return (NULL);
	if (i < 0)
		i = ft_strlen(buff) - 1;
	temp = (char *)ft_calloc(sizeof(char), i + 2);
	if (!temp)
		return (NULL);
	temp[i + 1] = 0;
	j = 0;
	while (j <= i)
	{
		temp[j] = buff[j];
		j++;
	}
	j = 0;
	while (buff[j])
	{
		if (j < ((int)ft_strlen(buff) - i - 1))
			buff[j] = buff[j + i + 1];
		else
			buff[j] = '\0';
		j++;
	}
	return (temp);
}
// temp should be freed later in main function when testing

/* ft_readfile function reads BUFFER_SIZE elements into temp buf 
and calls a join function ft_buffjoin that joins 
old buffer with temp buff and returns new malloced buffer;
old buffer is freed
returns negative value on error */
/*char	*ft_readfile(int fd, char *buffer)
{
	int		bytesread;
	char	newread[BUFFER_SIZE + 1];

	bytesread = read(fd, newread, BUFFER_SIZE);
	if (bytesread < 0)
		return (NULL);
	else if (bytesread == 0)
		return (buffer);
	while (bytesread <= BUFFER_SIZE)
		newread[bytesread++] = 0;
	buffer = ft_buffjoin(buffer, newread);
	if (!buffer)
		return (NULL);
	return (buffer);
}*/

/* if (read(fd, 0, 0) < 0) >> error occured */
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*newread;
	int			bytesread;

	bytesread = 0;
	if (fd == -1 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	newread = (char *)ft_calloc(1, BUFFER_SIZE + 1);
	if (!newread)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)ft_calloc(1, 1);
		if (!buffer)
		{
			free(newread);
			return (NULL);
		}
	}
	while (ft_checknl(buffer) < 0)
	{
		bytesread = read(fd, newread, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(buffer);
			free(newread);
			return (NULL);
		}
		else if (bytesread == 0)
		{
			free(newread);
			if (ft_strlen(buffer) == 0)
				return (NULL);
			return (ft_splitnl(buffer, ft_checknl(buffer)));
		}
		newread[bytesread] = 0;
		buffer = ft_buffjoin(buffer, newread);
		if (!buffer)
		{
			free(newread);
			return (NULL);
		}
		if (ft_strlen(buffer) == 0)
		{
			free(buffer);
			free(newread);
			return (NULL);
		}
	}
	free(newread);
	return (ft_splitnl(buffer, ft_checknl(buffer)));
}

/*char	*get_next_line_new_attempt(int fd)
{
	static char	*buffer; // I will keep everything here
	char		*newread; // everytime i read i will save it here
	int			bytesread;
	int			i;

	i = 0;
	bytesread = 0;
	if (fd == -1 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//printf("%d\n", BUFFER_SIZE);
	newread = (char *)ft_calloc(1, BUFFER_SIZE + 1);
	if (!newread)
		return (NULL);
	bytesread = read(fd, newread, BUFFER_SIZE);
	if (bytesread <= 0)
	{
		free(newread);
		return(NULL);
	}
	if (!buffer)
	{
		buffer = (char *)ft_calloc(1, 1);
		if (!buffer)
		{
			free(newread);
			return (NULL);
		}
	}
	while (ft_checknl(buffer) < 0)
	{
		if (i > 0)
		{
			bytesread = read(fd, newread, BUFFER_SIZE);
			if (bytesread < 0)
			{
				free(buffer);
				free(newread);
				return (NULL);
			}
			else if (bytesread == 0)
			{
				if (ft_strlen(buffer) == 0)
				{
					free(newread);
					//free(buffer);
					return (NULL);
				}
				free(newread);
				return (ft_splitnl(buffer, ft_checknl(buffer), bytesread));
			}
		}
		//i = bytesread;
		//while (i <= BUFFER_SIZE)
		//	newread[i++] = 0;
		buffer = ft_buffjoin(buffer, newread);
		if (!buffer)
		{
			free(newread);
			return (NULL);
		}
		if(ft_strlen(buffer) == 0)
		{
			free(newread);
			return (NULL);
		}
		i++;
	}
	free(newread);
	return (ft_splitnl(buffer, ft_checknl(buffer), bytesread));
}
*/

int	main(void)
{
	int		fd;
	char	*filepath;
	char	*line;

	filepath = "emptytest.txt";
	fd = open(filepath, O_RDONLY);
	//fd = 0;
	line = get_next_line(fd);
	printf("%s", line);
	while (line)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
	}
	//line = get_next_line(fd);
	if (line)
		free (line);
	close (fd);
	return (0);
}
