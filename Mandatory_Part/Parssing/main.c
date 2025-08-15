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


int	ft_get_source(char *file)
{
	int		fd;
	char	*result;

	fd = open(file, O_RDONLY);
	result = ft_get_next_line(fd);
	printf("result =====> %s\n", result);
	return (0);
}

int	main(int argc, char **argv)
{
	if (ft_parsing(argc, argv) == -1)
		return (1);
	if (ft_get_source(argv[1]) == -1)
		return (1);
}
