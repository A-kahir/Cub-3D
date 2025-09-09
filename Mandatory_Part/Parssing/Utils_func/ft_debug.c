/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:46:28 by akahir            #+#    #+#             */
/*   Updated: 2025/09/09 17:18:09 by akahir           ###   ########.fr       */
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
		if (tmp->player)
		{
			printf("player info: \n");
			printf("      player PX : %d\n", src->player->player_px);
			printf("      player PY : %d\n", src->player->player_py);
			printf("      player OR: %c\n", src->player->player_or);
		}
	}
}
