/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:30:23 by lhermann          #+#    #+#             */
/*   Updated: 2017/07/10 06:34:28 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		replace(char **store, char **line, int fd)
{
	t_struct gnl;

	gnl.i = -1;
	gnl.j = 0;
	if ((gnl.finligne = ft_strchr(store[fd], '\n')))
	{
		while (store[fd][gnl.i] != '\n')
			gnl.i++;
		gnl.tmp = ft_memalloc(gnl.i + 1);
		gnl.i = -1;
		while (store[fd][++gnl.i] != '\n')
			gnl.tmp[gnl.i] = store[fd][gnl.i];
		gnl.tmp[gnl.i] = '\0';
		gnl.i++;
		while (store[fd][gnl.i] != '\0')
		{
			store[fd][gnl.j++] = store[fd][gnl.i];
			store[fd][gnl.i++] = '\0';
		}
		while (store[fd][gnl.j] != '\0')
			store[fd][gnl.j++] = '\0';
		*line = gnl.tmp;
		return (1);
	}
	return (0);
}

int		delete_line(char **store, char **line, int fd)
{
	if (store[fd][0] != '\0')
	{
		*line = malloc(1);
		*line = "\0";
		*line = ft_strjoin(*line, store[fd]);
		ft_bzero(store[fd], ft_strlen(*line));
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char *store[NBFD];
	char		buffer[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	if (fd < 0 || BUFF_SIZE < 0 || read(fd, NULL, 0))
		return (-1);
	if (store[fd] == NULL)
		if (!(store[fd] = ft_strnew(1)))
			return (-1);
	if (replace(store, line, fd))
		return (1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		tmp = store[fd];
		store[fd] = ft_strjoin(store[fd], buffer);
		free(tmp);
		ft_bzero(buffer, ret);
		if (replace(store, line, fd))
			return (1);
	}
	if (delete_line(store, line, fd) == 1)
		return (1);
	return (0);
}
