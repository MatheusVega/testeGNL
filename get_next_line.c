/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathfern <mathfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 21:37:53 by mathfern          #+#    #+#             */
/*   Updated: 2021/07/11 00:34:09 by mathfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_valid_array(int read_size, char *buf, int fd)
{
	read_size = read(fd, buf, BUFFER_SIZE);
	if (read_size == -1)
		return (-1);
	buf[read_size] = '\0';
	return (read_size);
}

int	ft_valid_stock(char **stock, char *buf)
{
	*stock = ft_join(*stock, buf);
	if (*stock == NULL)
		return (-1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			read_size;
	char		buf[BUFFER_SIZE + 1];
	static char	*stock = NULL;

	if (line == NULL || fd < 0 || BUFFER_SIZE < 1 || (read(fd, buf, 0)) < 0)
		return (-1);
	read_size = 1;
	while (!(ft_newline_check(stock, read_size)))
	{
		read_size = ft_valid_array(read_size, buf, fd);
		ft_valid_stock(&stock, buf);
	}
	*line = ft_get_line(stock);
	if (*line == NULL)
		return (-1);
	stock = ft_trim(stock);
	if (stock == NULL)
		return (-1);
	if (read_size != 0)
		return (1);
	free(stock);
	stock = NULL;
	return (0);
}
