/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:49:14 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/11/18 13:24:23 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		join_str(char **line, char *str)
{
	char *tmp;

	tmp = *line;
	*line = ft_strjoin(*line, str);
	free(tmp);
	if (!*line)
		return (-1);
	return (0);
}

int		read_file(int fd, char *str, int n_read, char **line)
{
	if (!*str && n_read)
	{
		if ((n_read = read(fd, str, BUFFER_SIZE)) < 0)
			return (-1);
		str[n_read] = '\0';
	}
	return (set_line(str, line, n_read, fd));
}

int		set_line(char *str, char **line, int n_read, int fd)
{
	int		i;

	i = 0;
	if (n_read == 0 && !*str)
		return (0);
	while (str[i] != '\n' && str[i])
		++i;
	if (str[i] == '\n')
	{
		str[i] = '\0';
		if ((join_str(line, str)) == -1)
			return (-1);
		ft_strmove(str);
		return (1);
	}
	else if (str[i] == '\0')
	{
		if ((join_str(line, str)) == -1)
			return (-1);
		ft_memset(str, 0, BUFFER_SIZE);
		return (read_file(fd, str, n_read, line));
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char str[4096][BUFFER_SIZE < 0 ? 1 : BUFFER_SIZE + 1];
	int			n_read;

	if (fd < 0 || line == NULL || read(fd, str, 0) || BUFFER_SIZE <= 0)
		return (-1);
	n_read = BUFFER_SIZE;
	*line = ft_strdup("");
	return (set_line(str[fd], line, n_read, fd));
}
