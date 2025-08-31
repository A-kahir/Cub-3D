/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_source.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:30:44 by akahir            #+#    #+#             */
/*   Updated: 2025/08/31 18:30:46 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

static int ft_check_player(t_source *src)
{
	int player;
	int i;
	int j;

	player = 0;
	i = 0;
	while (src && src->map[i])
	{
		j = 0;
		while (src->map[i][j] != '\0')
		{
			if (src->map[i][j] == 'S' || src->map[i][j] == 'N' || src->map[i][j] == 'W' || src->map[i][j] == 'E')
				player++;
			j++;
		}
		i++;
	}
	if (player > 1)
		return (print_message(8, NULL ,'\0'), -1);
	else if (player == 0)
		return (print_message(9, NULL, '\0'), -1);
	return (0);
}

t_source *ft_get_source(t_source *src, char *file)
{
	int     fd;
	char    *line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("open"), NULL);
	while ((line = ft_get_next_line(fd)))
	{
		if (ft_chack_valid_source(line) == 0)
			src = ft_fill_struct(src, line);
		if (ft_strncmp(line, "C ", 2) == 0) 
		{
			free(line);
			break;
		}
		free(line);
	}
	if (ft_check_before_map(src) == -1)
		return (print_message(5, NULL, '\0'), NULL);
	if (ft_fill_the_map(fd, src) == NULL)
		return (NULL);
	if (ft_check_player(src) == -1)
		return (NULL);
	return (src);
}
