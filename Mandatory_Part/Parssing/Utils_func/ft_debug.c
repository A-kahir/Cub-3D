/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:46:28 by akahir            #+#    #+#             */
/*   Updated: 2025/09/10 17:08:15 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	ft_debug(t_source *src, int flag)
{
	t_source	*tmp;

	tmp = src;
	if (flag == 1)
	{
		while (tmp)
		{
			printf("tmp ===> %s = %s\n", tmp->var, tmp->value);
			if (tmp)
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
		if (tmp->player)
		{
			printf("player info: \n");
			printf("      player PX : %.2f\n", src->player->player_px);
			printf("      player PY : %.2f\n", src->player->player_py);
			printf("      player OR: %c\n", src->player->player_or);
			printf("      player Plan X : %.2f\n", src->player->plan_x);
			printf("      player Plan Y : %.2f\n", src->player->plan_y);
			printf("      player direction x : %.2f\n", src->player->dir_x);
			printf("      player direction y : %.2f\n", src->player->dir_y);
		}
	}
}
