/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 05:02:52 by ifaleh            #+#    #+#             */
/*   Updated: 2025/11/14 22:57:52 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	handle_mouse(t_source *src)
{
	int	current_x;
	int	current_y;

	mlx_mouse_get_pos(src->mlx_pointer, src->mlx_window,
		&current_x, &current_y);
	mouse_move(current_x, current_y, src);
}

void	norm_mouse(t_source *src, double rot_speed, int delta_x)
{
	double	angle;
	double	old_dir_x;
	double	old_plan_x;

	angle = rot_speed * delta_x * 0.002;
	old_dir_x = src->p->dir_x;
	src->p->dir_x = old_dir_x * cos(angle) - src->p->dir_y * sin(angle);
	src->p->dir_y = old_dir_x * sin(angle) + src->p->dir_y * cos(angle);
	old_plan_x = src->p->plan_x;
	src->p->plan_x = old_plan_x * cos(angle) - src->p->plan_y * sin(angle);
	src->p->plan_y = old_plan_x * sin(angle) + src->p->plan_y * cos(angle);
}

static char	*ft_get_sprite_path(int i, int flag)
{
	char	*image;
	char	*tmp;
	char	*path;
	char	*base;

	image = ft_itoa(i);
	if (!image)
		return (NULL);
	if (flag == 1)
		base = "Bonus_Part/Parssing_b/texture/HELL/sp/";
	else
		base = "Bonus_Part/Parssing_b/texture/PARADISE/sp/";
	tmp = ft_strjoin(base, image);
	path = ft_strjoin(tmp, ".xpm");
	return (path);
}

static int	ft_animate_sprites(t_source *src)
{
	t_sp_infos	sp;
	int			flag;

	1 && (sp.h = HEIGHT, sp.w = WIDTH / 2, sp.i = 0);
	flag = ft_static_flag(0, 0);
	while (sp.i <= 30)
	{
		sp.path = ft_get_sprite_path(sp.i, flag);
		if (!sp.path)
			return (ft_free_mlx(src), malloc_cl(0, 2), 1);
		sp.sprite = mlx_xpm_file_to_image(src->mlx_pointer, sp.path,
				&sp.w, &sp.h);
		if (sp.path)
			sp.path = NULL;
		if (!sp.sprite)
			return (ft_free_mlx(src), malloc_cl(0, 2), 1);
		sp.sp_x = (WIDTH - sp.w) / 2;
		sp.sp_y = HEIGHT - sp.h;
		mlx_put_image_to_window(src->mlx_pointer, src->mlx_window,
			sp.sprite, sp.sp_x, sp.sp_y);
		usleep(80000);
		mlx_destroy_image(src->mlx_pointer, sp.sprite);
		sp.i++;
	}
	return (0);
}

int	key_animation(int key, t_source *src)
{
	if (key == 110)
		return (ft_animate_sprites(src));
	return (0);
}
