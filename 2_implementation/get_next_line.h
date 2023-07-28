/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:59:26 by wel-safa          #+#    #+#             */
/*   Updated: 2023/07/27 19:23:26 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifdef BUFFER_SIZE
# else
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_checknl(char *buffer);
char	*ft_splitnl(char *buff, int i, int bytesread);
char	*ft_readfile(int fd, char *buffer);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_buffjoin(char *buffer, char const *buf);
char	*ft_strdup(const char *s);

#endif