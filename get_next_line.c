/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:58:39 by wel-safa          #+#    #+#             */
/*   Updated: 2023/07/17 19:45:59 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*readline;
	int		readret;
	char	buf[1];

	readret = 1;
	if (fd == -1)
		return (NULL);
	readline = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (!readline)
		return (NULL);
	readline[BUFFER_SIZE] = 0;
	while(readret != -1 && buf[0] != '\n' && buf[0] != '\0')
	{
		readret = read(fd, buf, 1);
		// copy character in buffer to the end of string in readline
	}
	
}

int	main(void)
{
	int	fd;
	char	*filepath;
	char	*line;

	filepath = "test.txt";
	fd = open(filepath, O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
	return 0;
}
