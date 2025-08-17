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

int ft_if_valid_map(char *line)
{
	static int save_line;
	int i;
	int len;

	i = 0;
	len = ft_strlen(line) - 3;
	while (line[i] != '\0')
	{
		if (save_line == 0 && line[i] != '1')
		{
			if (!(line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
			{
				write(2, "check your Map: You have invalid character: [", 46);
				write(2, &line[i], 1);
				write(2, "]", 2);
				write(2, " from the first line Map\n", 26);
				return (-1);
			}
		}
		else if (save_line > 0)
		{
			if (line[0] != '1')
			{
				if (!(line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
				{
					write(2, "check your Map: You have invalid character: [", 46);
				    write(2, &line[0], 1);
				    write(2, "]", 2);
				    write(2, " from the line Map: [", 22);
					write(2, line, ft_strlen(line) - 2);
				    write(2, "]\n", 3);
					return (-1);
				}
			}
			else if (line[len] != '1')
			{
				if (!(line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
				{
					write(2, "check your Map: You have invalid character: [", 46);
				    write(2, &line[len], 1);
				    write(2, "]", 2);
				    write(2, " from the line Map: [", 22);
					write(2, line, ft_strlen(line) - 2);
				    write(2, "]\n", 3);
					return (-1);
				}
			}
		}
		i++;
	}
	save_line++;
	return (0);
}

int ft_check_map(char *line)
{
	int i;

	i = 0;
	if (line[i] == '\n' || (line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
		return (-1);
	if (ft_if_valid_map(line) == -1)
	{
		return (-2);
	}
	return (0);
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
		if (line && ft_chack_valid_source(line) == 0)
			src = ft_fill_struct(src, line);
		if (ft_strchr(line, 'C'))
			break;
		line = ft_get_next_line(fd);
	}
	line = ft_get_next_line(fd);
	int check;
	while (line)
	{
		check = ft_check_map(line);
		if (line && check == -2)
			return (NULL);
		line = ft_get_next_line(fd);
	}
	if (check == 0)
	   printf("************\n");
	return (src);
}

int	main(int argc, char **argv)
{
	t_source	*src;

	src = NULL;
	if (ft_parsing(argc, argv) == -1)
		return (1);
	src = ft_get_source(src, argv[1]);
	if (!src)
		return (print_message(1), 1);
	// t_source *tmp = src;
	// while (tmp)
	// {
	// 	printf("tmp ===> %s = %s\n", tmp->var, tmp->value);
	// 	tmp = tmp->next;
	// }
}
