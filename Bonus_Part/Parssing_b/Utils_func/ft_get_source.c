/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_source.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:30:44 by akahir            #+#    #+#             */
/*   Updated: 2025/10/05 20:02:02 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

static int	ft_check_player(t_source *src)
{
	int	i;
	int	j;
	int	player;

	1 && (player = 0, i = 0);
	while (src && src->map[++i])
	{
		j = -1;
		while (src->map[i][++j] != '\0')
		{
			if (src->map[i][j] == 'S' || src->map[i][j] == 'N'
				|| src->map[i][j] == 'W' || src->map[i][j] == 'E')
			{
				src->p->p_px = j;
				src->p->p_py = i;
				src->p->p_or = src->map[i][j];
				player++;
			}
		}
	}
	if (player > 1)
		return (print_message(8, NULL, '\0'), -1);
	else if (player == 0)
		return (print_message(9, NULL, '\0'), -1);
	return (0);
}

int ft_stop_reading(t_source *src)
{
	static int NO;
	static int SO;
	static int WE;
	static int EA;
	static int F;
	static int C;
	static int DR;
	t_source *curr;

	curr = src;
	while (curr)
	{
		if (!ft_strcmp(curr->var, "DR"))
			DR = 1;
		else if (!ft_strcmp(curr->var, "NO"))
			NO = 1;
		else if (!ft_strcmp(curr->var, "SO"))
			SO = 1;
		else if (!ft_strcmp(curr->var, "WE"))
			WE = 1;
		else if (!ft_strcmp(curr->var, "EA"))
			EA = 1;
		else if (!ft_strcmp(curr->var, "F"))
			F = 1;
		else if (!ft_strcmp(curr->var, "C"))
			C = 1;
		curr = curr->next;
	}
	printf("NO=%d SO=%d WE=%d EA=%d F=%d C=%d DR=%d\n\n", NO, SO, WE, EA, F, C, DR);
	if (NO && SO && WE && EA && F && C)
		return (0);
	return (-1);
}

t_source	*ft_get_source(t_source *src, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("open"), NULL);
	line = ft_get_next_line(fd);
	while (line)
	{
		if (ft_chack_valid_source(line) == 0)
			src = ft_fill_struct(src, line);
		if (ft_stop_reading(src) == 0)
		{
			free(line);
			break ;
		}
		free(line);
		line = ft_get_next_line(fd);
	}
	if (ft_check_before_map(src) == -1)
		return (print_message(5, NULL, '\0'), NULL);
	if (ft_fill_the_map(fd, src) == NULL || ft_check_player(src) == -1)
		return (NULL);
	return (src);
}
