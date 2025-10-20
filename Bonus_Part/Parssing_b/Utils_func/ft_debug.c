/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:46:28 by akahir            #+#    #+#             */
/*   Updated: 2025/10/20 14:22:58 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

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
	int			i;

	tmp = src;
	if (flag == 1)
	{
		if (tmp && tmp->colors)
		{
			if (tmp->colors->hexa_rgb_f)
				printf("tmp->colors->hexa_rgb_f ==> %d\n", tmp->colors->hexa_rgb_f);
			if (tmp->colors->hexa_rgb_c)
				printf("tmp->colors->hexa_rgb_c ==> %d\n", tmp->colors->hexa_rgb_c);
		}
		while (tmp)
		{
			printf("tmp ===> %s = %s\n", tmp->var ? tmp->var : "(null)", tmp->value ? tmp->value : "(null)");
			tmp = tmp->next;
		}
		printf("\n*************************************=> MAP <=*************************************\n\n");
		i = 0;
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
		if (tmp && tmp->p)
		{
			printf("player info: \n");
			printf("      player PX : %f\n", tmp->p->p_px);
			printf("      player PY : %f\n", tmp->p->p_py);
			printf("      player OR: %c\n", tmp->p->p_or);
		}
	}

	if (flag == 3)
	{
		while (tmp)
		{
			if (tmp->door)
			{
				t_doors *d = tmp->door;
				while (d)
				{
					printf("Door info : \n");
					printf("      Door Index : %d\n", tmp->door->index);
					printf("      Door X : %d\n", tmp->door->x);
					printf("      Door Y : %d\n\n", tmp->door->y);
					d = d->next;
				}
			}
			tmp = tmp->next;
		}
	}
	if (flag == 4)
	{
		while (tmp)
		{
			if (tmp->sprites)
			{
				t_sprites *s = tmp->sprites;
				while (s)
				{
					printf("Animated sprite info:\n");
					printf("      sprite Index : %d\n", s->index);
					printf("      sprite X     : %d\n", s->x);
					printf("      sprite Y     : %d\n\n", s->y);
					s = s->next;
				}
			}
			tmp = tmp->next;
		}
		return;
	}
}

