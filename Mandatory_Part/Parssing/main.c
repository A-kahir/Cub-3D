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
		return (print_message(0, NULL, '\0'), -1);
	if (argv[1])
		if (ft_strcmp(argv[1], "source.cub") != 0)
			return (print_message(1, NULL, '\0'), -1);
	return (0);
}

int ft_count_struct(t_source *src)
{
	int count;

	count = 0;
	while (src)
	{
		count++;
		src = src->next;
	}
	return (count);
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
	if (ft_count_struct(src) < 6)
		return (print_message(5, NULL, '\0'), NULL);
    if (ft_fill_the_map(fd, src) == NULL)
		return (NULL);
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
		return (print_message(1, NULL, '\0'), 1);
	t_source *tmp = src;
	while (tmp)
	{
		printf("tmp ===> %s = %s\n", tmp->var, tmp->value);
		tmp = tmp->next;
	}
	printf("*********************\n");
	int i = 0;
	while (src->map[i])
	{
		printf("%s\n", src->map[i]);
		i++;
	}
}
