/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:58:39 by wel-safa          #+#    #+#             */
/*   Updated: 2023/07/18 20:38:19 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*rest;

	temp = 0;
	if (fd == -1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (/* Buffer has a new line in it*/)
	{
		// We have to return everything before new line.
		// and keep the rest saved in the static variable.
	}
	rest = ft_restcpy(buffer);// copy buffer to rest
	// free buffer
	buffer = (char *)ft_calloc(BUFFER_SIZE + ft_strlen(rest) + 1, 1);
	if (!buffer)
		return (NULL);
	read(fd, buffer, 1);
	return (buffer);
}

int	main(void)
{
	int		fd;
	char	*filepath;
	char	*line;

	filepath = "test.txt";
	fd = open(filepath, O_RDONLY);
	//fd = 0;
	line = get_next_line(fd);
	while(line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return 0;
}
