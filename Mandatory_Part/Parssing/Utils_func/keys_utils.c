/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 02:05:16 by ifaleh            #+#    #+#             */
/*   Updated: 2025/11/11 00:28:34 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_mand.h"

void	init_keys(t_source *src)
{
	src->keys.w = 0;
	src->keys.a = 0;
	src->keys.s = 0;
	src->keys.d = 0;
	src->keys.left = 0;
	src->keys.right = 0;
	src->keys.esc = 0;
}

int	key_press(int key, t_source *src)
{
	if (key == 119)
		src->keys.w = 1;
	else if (key == 97)
		src->keys.a = 1;
	else if (key == 115)
		src->keys.s = 1;
	else if (key == 100)
		src->keys.d = 1;
	else if (key == 65361)
		src->keys.left = 1;
	else if (key == 65363)
		src->keys.right = 1;
	else if (key == 65307)
		src->keys.esc = 1;
	key_events(src);
	init_keys(src);
	return (0);
}
