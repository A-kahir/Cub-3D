/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_the_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 02:53:12 by akahir            #+#    #+#             */
/*   Updated: 2025/08/21 17:14:30 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

int ft_check_last_line_map(t_source *src)
{
    int i;
    int j;

    i = 0;
    while (src && src->map[i])
    {
        if (src->map[i + 1] == NULL)
            break ;
        i++;
    }
    j = 0;
    while (src && src->map && src->map[i] && src->map[i][j] != '\0')
    {
        if (src->map[i][j] != '1')
        {
            if (!(src->map[i][j] == 32 || src->map[i][j] == '\n'
                || (src->map[i][j] >= 9 && src->map[i][j] <= 13)))
                    return (print_message(6, NULL, src->map[i][j]), -1);
        }
        j++;
    }
    return (0);
}

void *ft_fill_the_map(int fd, t_source *src)
{
	char *line;
	char **map;
    int i;
	int j;

	1 && (i = 0, map = NULL);
    while ((line = ft_get_next_line(fd)))
    {
        if (!(line[0] == '\n' ||  line[0] == '\0'
            || (line[0] == 32 || (line[0] >= 9 && line[0] <= 13))))
        {
			int len = ft_strlen(line);
			if (line[len - 2] == '\r')
				line[len - 2] = '\0';
			if (len > 0 && line[len - 1] == '\n')
				line[len - 1] = '\0';
            char **new_map = malloc_cl(sizeof(char *) * (i + 2), 0);
            if (!new_map)
                return (perror("map malloc"), NULL);
			j = 0;
            while (j < i)
			{
                new_map[j] = map[j];
				j++;
			}
            free(map);
            new_map[i] = ft_strdup(line, 0);
            new_map[i + 1] = NULL;
            map = new_map;
            i++;
        }
        free(line);
    }
	int check;
	i = 0;
	while (map[i])
	{
		check = ft_check_map(map[i]);
		if (check == -2)
			return (NULL);
		i++;
	}
	if (src)
	{
		src->map = malloc_cl(sizeof(char *) * (i + 1), 0);
		if (!src->map)
			return (perror("src map failed"), NULL);
	}
	if (src && check == 0)
	{
		j = 0;
		while (j < i)
		{
			src->map[j] = ft_strdup(map[j], 0);
			j++;
		}
	}
	if (src)
		src->map[i] = NULL;
    if (ft_check_last_line_map(src) == -1)
        return (NULL);
	return (src);
}
