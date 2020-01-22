/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:41:11 by julnolle          #+#    #+#             */
/*   Updated: 2020/01/22 16:01:59 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_strjoin_back(char *back, char **src)
{
	char *tmp;

	if (back == NULL || *src == NULL)
		return ;
	tmp = ft_strdup(*src);
	free(*src);
	*src = ft_strjoin(tmp, back);
	free(tmp);
}

int		ft_strchr_pos(const char *s, int c)
{
	size_t pos;

	pos = 0;
	while (*s != c)
	{
		if (*s == '\0')
			return (-1);
		s++;
		pos++;
	}
	return (pos);
}

void	ft_read_line(char **str, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret;

	while (ft_strchr_pos(*str, '\n') == -1 || ft_strchr_pos(*str, '\0') == -1)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[ret] = '\0';
			ft_strjoin_back(buf, str);
		}
		else
			return ;
	}
}

int		ft_fill_line(char **line, char **str)
{
	ssize_t	pos;
	char	*tmp;

	pos = 0;
	if ((pos = ft_strchr_pos(*str, '\n')) != -1)
	{
		*line = ft_substr(*str, 0, pos);
		tmp = ft_strdup(*str);
		free(*str);
		*str = ft_strdup(tmp + pos + 1);
		free(tmp);
		return (1);
	}
	else if (ft_strchr_pos(*str, '\0') != -1)
	{
		*line = *str;
		free(*str);
		return (0);
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || BUFFER_SIZE > 65535)
		return (-1);
	if (!str)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	if (str)
	{
		ft_read_line(&str, fd);
		return (ft_fill_line(line, &str));
	}
	return (-1);
}
