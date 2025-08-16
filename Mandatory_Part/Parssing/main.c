/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:08:25 by akahir            #+#    #+#             */
/*   Updated: 2025/08/15 16:08:25 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_parsing(int argc, char **argv)
{
	if (argc != 2)
		return (print_message(0), -1);
	if (argv[1])
		if (ft_strcmp(argv[1], "source.cub") != 0)
			return (print_message(1), -1);
	return (0);
}

t_source *ft_fill_struct(t_source *src, char *line)
{
	char **var;

	if (!line)
		return (NULL);
	var = ft_split(line, ' ');
	if (!var)
		return (perror("split"), NULL);
	if (var && ft_strncmp(var[0], "NO", 2) == 0)
		src = ft_add_back(src, var[0], var[1]);
	else if (var && ft_strncmp(var[0], "SO", 2) == 0)
		src = ft_add_back(src, var[0], var[1]);
	else if (var && ft_strncmp(var[0], "WE", 2) == 0)
		src = ft_add_back(src, var[0], var[1]);
	else if (var && ft_strncmp(var[0], "EA", 2) == 0)
		src = ft_add_back(src, var[0], var[1]);
	else if (var && ft_strcmp(var[0], "F") == 0)
		src = ft_add_back(src, var[0], var[1]);
	else if (var && ft_strcmp(var[0], "C") == 0)
		src = ft_add_back(src, var[0], var[1]);
	return (src);
}

t_source	*ft_get_source(t_source *src, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("fd"), NULL);
	line = ft_get_next_line(fd);
	if (!line)
		return (perror("line"), NULL);
	while (line)
	{
		if (ft_chack_valid_source(line) == 0)
			src = ft_fill_struct(src, line);
		line = ft_get_next_line(fd);
	}
	return (src);
}

int	main(int argc, char **argv)
{
	t_source	*src;

	src = malloc_cl(sizeof(t_source), 0);
	if (!src)
		return (perror("malloc"), 1);
	if (ft_parsing(argc, argv) == -1)
		return (1);
	src = ft_get_source(src, argv[1]);
	if (!src)
		return (print_message(1), 1);
	t_source *tmp = src;
	while (tmp)
	{
		printf("tmp ===> %s = %s\n$", tmp->var, tmp->value);
		tmp = tmp->next;
	}
}
