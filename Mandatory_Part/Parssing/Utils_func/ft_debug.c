/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:46:28 by akahir            #+#    #+#             */
/*   Updated: 2025/09/27 18:29:02 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_mand.h"

void	ft_debug_map(char *map, int pos)
{
	int	i;

	i = 0;
	while (pos > i)
	{
		printf(" ");
		i++;
	}
	printf("i\n");
	printf("%s\n\n", map);
}

void	ft_debug(t_source *src, int flag)
{
	t_source	*tmp;

	tmp = src;
	if (flag == 1)
	{
		while (tmp)
		{
			printf("tmp ===> %s = %s\n", tmp->var, tmp->value);
			if (tmp->colors)
			{
				if (tmp->colors->hexa_rgb_f)
					printf("tmp->colors->hexa_rgb_f ==> %d\n", tmp->colors->hexa_rgb_f);
				if (tmp->colors->hexa_rgb_c)
					printf("tmp->colors->hexa_rgb_c ==> %d\n", tmp->colors->hexa_rgb_c);
			}
			tmp = tmp->next;
		}
		printf("\n*************************************=> MAP <=*************************************\n\n");
		int i = 0;
		tmp = src;
		if (tmp->map)
		{
			while (tmp->map[i])
			{
				printf("%s\n", tmp->map[i]);
				i++;
			}
		}
	}
	if (flag == 2)
	{
		if (tmp->p)
		{
			printf("player info: \n");
			printf("      player PX : %f\n", src->p->p_px);
			printf("      player PY : %f\n", src->p->p_py);
			printf("      player OR: %c\n", src->p->p_or);
		}
	}
}
