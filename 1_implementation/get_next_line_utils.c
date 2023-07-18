/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:36:48 by wel-safa          #+#    #+#             */
/*   Updated: 2023/07/18 20:38:22 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		n++;
		s++;
	}
	return (n);
}

char	*ft_restcpy(char *buffer)
{
	int	i;

	i = 0;
	rest = (char *)malloc(ft_strlen(buffer) + 1);
	if (!rest)
		return NULL;
	while(buffer[i])
	{
		rest[i] = buffer[i];
		i++;
	}
	rest[i] = 0;
	return (rest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*ptr;

	bytes = size * nmemb;
	if (size != 0 && nmemb != 0 && bytes / size != nmemb)
		return (NULL);
	ptr = malloc (bytes);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, bytes);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void	ft_readcat(char *readline, char *buf)
{
	size_t	i;

	i = 0;
	if (!readline)
		return ;
	while(readline[i])
		i++;
	readline[i] = buf[0];
}

/*int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while(s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s2[i])
		return (s1[i] - s2[i]);
	return (0);
}*/