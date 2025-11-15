/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:30:04 by akahir            #+#    #+#             */
/*   Updated: 2025/11/14 02:24:28 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

int	ft_parsing(int argc, char **argv)
{
	if (argc != 2)
		return (print_message(0, NULL, '\0'), -1);
	if (argv[1])
		if (ft_strstr(argv[1], ".cub") == NULL)
			return (print_message(1, NULL, '\0'), -1);
	return (0);
}

void	ft_norm_check_hexa(t_source *curr)
{
	int	i;

	i = 0;
	while (curr->value[i++])
		if ((curr->value[i] == ',' && curr->value[i + 1] == ',')
			|| curr->value[0] == ',')
			return (print_message(11, NULL, '\0'), malloc_cl(0, 2),
				(void) NULL);
}

int	handle_close(t_source *src)
{
	ft_free_mlx(src);
	malloc_cl(0, 1);
	exit(0);
}

void	norm_mini(t_minimp *mmp, int map_h, int	*map_row_len)
{
	ft_cadring_outside(mmp, *map_row_len, map_h);
	ft_fix_negative(mmp);
	ft_calc_demonsions(mmp);
}

void	norm_render(t_source *src, int *i, double *time)
{
	*i = -1;
	*time = get_time();
	if (*time == -1)
	{
		ft_free_mlx(src);
		malloc_cl(0, 2);
	}
	src->frame_time = (*time - src->old_time) / 1000;
	if (src->frame_time == 0)
		src->frame_time = 0.0001;
	src->old_time = *time;
}
