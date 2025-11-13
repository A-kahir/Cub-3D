/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 18:03:21 by akahir            #+#    #+#             */
/*   Updated: 2025/11/08 01:59:50 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

static	char	*ft_operation(char *str, char *temp, char *buff)
{
	if (!str)
		temp = ft_strdup(buff);
	else
	{
		temp = ft_strjoin(str, buff);
		if (temp == NULL)
			return (free(buff), free(str), NULL);
	}
	return (temp);
}

static	char	*continue_rd(char *str, int fd, char *buff)
{
	int		rd;
	char	*temp;

	temp = NULL;
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
			return (free(buff), free(str), NULL);
		if (rd == 0)
			break ;
		buff[rd] = '\0';
		temp = ft_operation(str, temp, buff);
		if (temp == NULL)
			return (free(buff), NULL);
		str = temp;
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (str);
}

static char	*return_and_save(char *newline_pos, char **str, char **line)
{
	char	*temp;

	if (newline_pos)
	{
		*newline_pos = '\0';
		*line = ft_strdup(*str);
		temp = ft_strdup(newline_pos + 1);
		if (!(*line) || !temp)
			return (free(*str), *str = NULL, free(*line), free(temp), NULL);
		*str = temp;
		temp = ft_strjoin(*line, "\n");
		if (temp == NULL)
			return (free(*str), *str = NULL, free(*line), NULL);
		*line = temp;
	}
	else
	{
		*line = ft_strdup(*str);
		*str = NULL;
	}
	return (*line);
}

char	*ft_get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*newline_pos;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = malloc_cl((size_t)BUFFER_SIZE + 1, 0);
	if (buff == NULL)
		return (NULL);
	str = continue_rd(str, fd, buff);
	if (!str || *str == '\0')
		return (NULL);
	newline_pos = ft_strchr(str, '\n');
	return (return_and_save(newline_pos, &str, &line));
}
