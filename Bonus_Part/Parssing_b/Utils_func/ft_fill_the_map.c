/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_the_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 02:53:12 by akahir            #+#    #+#             */
/*   Updated: 2025/11/06 22:21:44 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

static int	ft_add_line(t_source *src, char *line, int i)
{
	int		len;
	int		j;
	char	**tmp;

	len = ft_strlen(line);
	while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
		line[--len] = '\0';
	if (len == 0)
		return (i);
	tmp = malloc_cl(sizeof(char *) * (i + 2), 0);
	if (!tmp)
		return (perror("malloc failed"), -1);
	j = -1;
	while (++j < i)
		tmp[j] = src->map[j];
	src->map = tmp;
	src->map[i] = malloc_cl(len + 1, 0);
	if (!src->map[i])
		return (perror("malloc failed"), -1);
	j = -1;
	while (line[++j])
		src->map[i][j] = line[j];
	src->map[i][j] = '\0';
	src->map[++i] = NULL;
	return (i);
}

static void	*ft_check_dr(int fd, t_source *src, char **line)
{
	while (*line && !ft_strncmp(*line, "DR", 2))
	{
		if (ft_chack_valid_source(src, *line) == 0)
			src = ft_fill_struct(src, *line);
		*line = ft_get_next_line(fd);
		while (*line && ((*line)[0] == 32 || ((*line)[0] >= 9
			&& (*line)[0] <= 13) || (*line)[0] == '\n' || (*line)[0] == '\0'))
			*line = ft_get_next_line(fd);
	}
	return (src);
}

static int	ft_read_map_lines(int fd, t_source *src, char **line)
{
	int	i;

	i = 0;
	while (*line)
	{
		if (!ft_strncmp(*line, "DR", 2))
			src = ft_fill_struct(src, *line);
		else
		{
			if ((*line)[0] == '\n' || (*line)[0] == '\0')
				break ;
			i = ft_add_line(src, *line, i);
			if (i < 0)
				return (-1);
		}
		*line = ft_get_next_line(fd);
	}
	return (i);
}

void	*ft_fill_the_map(int fd, t_source *src)
{
	char	*line;
	int		i;

	src->map = NULL;
	line = ft_get_next_line(fd);
	while (line && (line[0] == '\n' || line[0] == '\0'))
		line = ft_get_next_line(fd);
	src = ft_check_dr(fd, src, &line);
	i = ft_read_map_lines(fd, src, &line);
	if (i < 0)
		return (NULL);
	if (src->map)
		src->map[i] = NULL;
	line = ft_get_next_line(fd);
	if (line != NULL)
		return (NULL);
	if (ft_parse_map(src) == -1 || ft_stop_reading(src) == -1)
		return (NULL);
	return (src);
}
