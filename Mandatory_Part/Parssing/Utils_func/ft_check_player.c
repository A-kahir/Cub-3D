/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:26:54 by ifaleh            #+#    #+#             */
/*   Updated: 2025/11/11 17:49:00 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_mand.h"

int	ft_check_player(t_source *src)
{
	int	i;
	int	j;
	int	player;

	1 && (player = 0, i = 0);
	while (src && src->map && src->map[++i])
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

t_source	*ft_get_source(t_source *src, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("open"), NULL);
	src = ft_read_lines(fd, src);
	if (ft_check_before_map(src) == -1)
		return (print_message(5, NULL, '\0'), close(fd), NULL);
	if (ft_fill_the_map(fd, src) == NULL || ft_check_player(src) == -1)
		return (close(fd),NULL);
	return (close(fd), src);
}
