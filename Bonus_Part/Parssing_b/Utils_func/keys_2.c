/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 05:02:52 by ifaleh            #+#    #+#             */
/*   Updated: 2025/11/04 16:47:23 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	norm_mouse1(t_source *src, double rot_speed, int delta_x)
{
	double		old_d;
	double		old_p;

	old_d = src->p->dir_x;
	src->p->dir_x = old_d * cos(-rot_speed * (-delta_x) * 0.0005)
		- src->p->dir_y * sin(-rot_speed * (-delta_x) * 0.0005);
	src->p->dir_y = old_d * sin(-rot_speed * (-delta_x) * 0.0005)
		+ src->p->dir_y * cos(-rot_speed * (-delta_x) * 0.0005);
	old_p = src->p->plan_x;
	src->p->plan_x = old_p * cos(-rot_speed * (-delta_x) * 0.0005)
		- src->p->plan_y * sin(-rot_speed * (-delta_x) * 0.0005);
	src->p->plan_y = old_p * sin(-rot_speed * (-delta_x) * 0.0005)
		+ src->p->plan_y * cos(-rot_speed * (-delta_x) * 0.0005);
}

void	norm_mouse(t_source *src, double rot_speed, int delta_x)
{
	double		old_d;
	double		old_p;

	if (delta_x > 0)
	{
		old_d = src->p->dir_x;
		src->p->dir_x = old_d * cos(rot_speed * delta_x * 0.0005)
			- src->p->dir_y * sin(rot_speed * delta_x * 0.0005);
		src->p->dir_y = old_d * sin(rot_speed * delta_x * 0.0005)
			+ src->p->dir_y * cos(rot_speed * delta_x * 0.0005);
		old_p = src->p->plan_x;
		src->p->plan_x = old_p * cos(rot_speed * delta_x * 0.0005)
			- src->p->plan_y * sin(rot_speed * delta_x * 0.0005);
		src->p->plan_y = old_p * sin(rot_speed * delta_x * 0.0005)
			+ src->p->plan_y * cos(rot_speed * delta_x * 0.0005);
	}
	else if (delta_x < 0)
		norm_mouse1(src, rot_speed, delta_x);
}

static char	*ft_get_sprite_path(int i, int flag)
{
	char	*image;
	char	*tmp;
	char	*path;
	char	*base;

	image = ft_itoa(i);
	if (flag == 1)
		base = "Bonus_Part/Parssing_b/texture/HELL/sp/";
	else
		base = "Bonus_Part/Parssing_b/texture/PARADISE/sp/";
	tmp = ft_strjoin(base, image);
	path = ft_strjoin(tmp, ".xpm");
	free(tmp);
	return (path);
}

static int	ft_animate_sprites(t_source *src)
{
	t_sp_infos	sp;
	int			flag;

	sp.h = HEIGHT;
	sp.w = WIDTH / 2;
	sp.i = 0;
	flag = ft_static_flag(0, 0);
	while (sp.i <= 30)
	{
		sp.path = ft_get_sprite_path(sp.i, flag);
		sp.sprite = mlx_xpm_file_to_image(src->mlx_pointer, sp.path,
				&sp.w, &sp.h);
		if (sp.path)
		{
			free(sp.path);
			sp.path = NULL;
		}
		if (!sp.sprite)
			return (exit(1), 1);
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
