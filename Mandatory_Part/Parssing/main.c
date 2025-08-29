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
