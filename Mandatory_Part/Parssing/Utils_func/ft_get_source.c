/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_source.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:30:44 by akahir            #+#    #+#             */
/*   Updated: 2025/11/03 23:02:04 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_mand.h"

void	init_chars(t_chars *c)
{
	c->no = 0;
	c->so = 0;
	c->we = 0;
	c->ea = 0;
	c->f = 0;
	c->c = 0;
}

static void	ft_check_dir(t_source *curr, t_chars *c)
{
	if (!ft_strcmp(curr->var, "NO"))
		c->no = 1;
	else if (!ft_strcmp(curr->var, "SO"))
		c->so = 1;
	else if (!ft_strcmp(curr->var, "WE"))
		c->we = 1;
	else if (!ft_strcmp(curr->var, "EA"))
		c->ea = 1;
	else if (!ft_strcmp(curr->var, "F"))
		c->f = 1;
	else if (!ft_strcmp(curr->var, "C"))
		c->c = 1;
}

int	ft_stop_reading(t_source *src)
{
	t_chars		c;
	t_source	*curr;

	curr = src;
	init_chars(&c);
	while (curr)
	{
		ft_check_dir(curr, &c);
		curr = curr->next;
	}
	if (c.no && c.so && c.we && c.ea && c.f && c.c)
		return (0);
	return (-1);
}

static char	*ft_skip_line(char *line, int fd)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (line[0] == '\n' || ft_is_spaces(line[0]) == 0)
		return (ft_get_next_line(fd));
	return (line);
}

t_source	*ft_read_lines(int fd, t_source *src)
{
	char	*line;

	line = ft_get_next_line(fd);
	while (line)
	{
		line = ft_skip_line(line, fd);
		if (!line || line[0] == '\n' || ft_is_spaces(line[0]) == 0)
		{
			if (line)
				line = ft_get_next_line(fd);
			continue ;
		}
		if (ft_chack_valid_source(src, line) == 0)
			src = ft_fill_struct(src, line);
		if (ft_stop_reading(src) == 0)
			break ;
		line = ft_get_next_line(fd);
	}
	return (src);
}
