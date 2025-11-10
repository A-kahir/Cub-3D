/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaleh <ifaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 05:43:49 by ifaleh            #+#    #+#             */
/*   Updated: 2025/11/11 00:39:29 by ifaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_mand.h"

void	init_wall_params(t_wall_draw *w, int params[4], t_source *src)
{
	w->i = params[0];
	w->draw_start = params[1];
	w->draw_end = params[2];
	w->lineheight = params[3];
	w->drawing = w->draw_start;
	w->tex_x = calculate_tex_x(src, src->ray, w->tex);
}

int	get_adjusted_tex_x(t_wall_draw *w, t_tex *tex)
{
	int	adjusted_tex_x;

	adjusted_tex_x = w->tex_x;
	if (adjusted_tex_x >= tex->width)
		adjusted_tex_x = tex->width - 1;
	return (adjusted_tex_x);
}

int	get_texture_color(t_tex *tex, int tex_x, int tex_y)
{
	int	color;

	if (tex_y < 0)
		tex_y = 0;
	else if (tex_y >= tex->height)
		tex_y = tex->height - 1;
	color = *(unsigned int *)(tex->data + (tex_y * tex->line_len
				+ tex_x * (tex->bpp / 8)));
	return (color);
}

void	draw_texture_line(char *data, t_source *src, t_wall_draw *w,
	t_tex *tex)
{
	double	texpos;
	int		texy;
	int		adjusted_tex_x;
	int		color;
	t_pixel	p;

	while (w->drawing <= w->draw_end)
	{
		texpos = (w->drawing - HEIGHT / 2.0 + w->lineheight / 2.0)
			* tex->height / w->lineheight;
		texy = (int)texpos % tex->height;
		adjusted_tex_x = get_adjusted_tex_x(w, tex);
		color = get_texture_color(tex, adjusted_tex_x, texy);
		p.x = w->i;
		p.y = w->drawing;
		my_put_pixel(data, src, p, color);
		w->drawing++;
	}
}
