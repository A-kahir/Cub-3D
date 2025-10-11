/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_the_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 02:53:12 by akahir            #+#    #+#             */
/*   Updated: 2025/10/11 14:41:17 by akahir           ###   ########.fr       */
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
		return (free(line), i);
	tmp = malloc_cl(sizeof(char *) * (i + 2), 0);
	if (!tmp)
		return (perror("malloc failed"), -1);
	j = -1;
	while (++j < i)
		tmp[j] = src->map[j];
	src->map = tmp;
	src->map[i] = malloc_cl(sizeof(char) * (len + 1), 0);
	if (!src->map[i])
		return (perror("malloc failed"), -1);
	j = -1;
	while (line[++j])
		src->map[i][j] = line[j];
	src->map[i][j] = '\0';
	return (free(line), src->map[++i] = NULL, i);
}

void	*ft_fill_the_map(int fd, t_source *src)
{
	char	*line;
	int		i;

	1 && (i = 0, src->map = NULL, line = ft_get_next_line(fd));
	while (line && (ft_is_spaces(line[0]) == 0
		|| line[0] == '\n' || line[0] == '\0'))
		line = ft_get_next_line(fd);
	if (line && !ft_strncmp(line, "DR", 2))
	{
		if (ft_chack_valid_source(line) == 0)
			src = ft_fill_struct(src, line);
		line = ft_get_next_line(fd);
		while (line && (line[0] == 32 || (line[0] >= 9 && line[0] <= 13)
				|| line[0] == '\n' || line[0] == '\0'))
			line = ft_get_next_line(fd);
	}
	if (line == NULL)
		return (NULL);
	while (line)
	{
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			break ;
		}
		if (line[0] != '0' && line[0] != '1' && line[0] != ' ' && line[0] != 'D'
			&& line[0] != '\t')
		{
			free(line);
			break;
		}
		i = ft_add_line(src, line, i);
		if (i < 0)
			return (NULL);
		line = ft_get_next_line(fd);
	}
	1 && (src->map[i] = NULL, line = ft_get_next_line(fd));
	if (line != NULL)
		return (NULL);
	if (ft_parse_map(src) == -1)
		return (NULL);
	return (src);
}
