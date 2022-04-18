/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladelpinoramirez <pauladelpinoramire    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:17:08 by pdel-pin          #+#    #+#             */
/*   Updated: 2022/02/12 12:25:32 by pauladelpin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_read_it(int fd, char **str, char *buff, ssize_t bytes_read)
{
	char	*saved;

	saved = 0;
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		if (!(*str))
			(*str) = ft_calloc(sizeof(char), BUFFER_SIZE);
		saved = ft_strjoin((*str), buff);
		free((*str));
		(*str) = saved;
		if (ft_strchr(buff, '\n'))
			break ;
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
}

static void	*ft_get_line(char **str)
{
	char	*line;
	char	*saved;
	int		len;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len])
		len++;
	if ((*str)[len] == '\n')
	{
		line = ft_substr(*str, 0, len + 1);
		saved = ft_strdup(*str + len + 1);
		free(*str);
		*str = saved;
		if (!**str)
		{
			free(*str);
			*str = NULL;
		}
	}
	else
	{
		line = ft_strdup(*str);
		free(*str);
		*str = 0;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str[FILE_SIZE];
	char		*buff;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (buff);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(buff);
		return (NULL);
	}
	ft_read_it(fd, str, buff, bytes_read);
	if (!bytes_read && (!*str || !**str))
		return (NULL);
	line = ft_get_line(&(*str));
	return (line);
}
