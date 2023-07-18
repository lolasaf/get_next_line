/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:58:39 by wel-safa          #+#    #+#             */
/*   Updated: 2023/07/18 18:38:05 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*readline;
	static int	readret = 1;
	char	buf[1];

	//readret = 1;
	if (!readret)
		return (NULL);
	buf[0] = 1;
	if (fd == -1 || read(fd, 0, 0) < 0)
		return (NULL);
	readline = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (!readline)
		return (NULL);
	while(readret > 0 && buf[0] != '\n')
	{
		readret = read(fd, buf, 1);
		ft_readcat(readline, buf);
	}
	return (readline);
}

/*int	main(void)
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
}*/
