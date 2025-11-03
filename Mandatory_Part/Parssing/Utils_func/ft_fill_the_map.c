/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_the_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 02:53:12 by akahir            #+#    #+#             */
/*   Updated: 2025/10/31 17:40:03 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_mand.h"

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

static int	ft_read_map_lines(int fd, t_source *src, char **line)
{
	int	i;

	i = 0;
	while (*line)
	{
		if ((*line)[0] == '\n' || (*line)[0] == '\0')
			break ;
		i = ft_add_line(src, *line, i);
		if (i < 0)
			return (-1);
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
