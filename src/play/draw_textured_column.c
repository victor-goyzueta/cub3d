/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textured_column.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 01:04:40 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/15 01:06:19 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	*get_wall_texture(t_cub *cub)
{
	if (cub->ray.side == 0)
	{
		if (cub->ray.dir_x > 0)
			return (&cub->textures[TEX_EAST]);
		return (&cub->textures[TEX_WEST]);
	}
	if (cub->ray.dir_y > 0)
		return (&cub->textures[TEX_SOUTH]);
	return (&cub->textures[TEX_NORTH]);
}

static void	calculate_wall_x(t_cub *cub)
{
	if (cub->ray.side == 0)
		cub->ray.wall_x = cub->player.pos_y
			+ cub->ray.wall_dist * cub->ray.dir_y;
	else
		cub->ray.wall_x = cub->player.pos_x
			+ cub->ray.wall_dist * cub->ray.dir_x;
	cub->ray.wall_x = cub->ray.wall_x - (int)cub->ray.wall_x;
}

static void	update_ray_tex(t_cub *cub, t_img *tex)
{
	if (!cub || !tex)
		return ;
	if (cub->ray.tex_y < 0)
		cub->ray.tex_y = 0;
	if (cub->ray.tex_y >= tex->height)
		cub->ray.tex_y = tex->height - 1;
}

static int	get_texture_pixel(t_img *texture, int x, int y)
{
	char	*dest;

	dest = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	return (*(unsigned int *)dest);
}

void	draw_textured_column(t_cub *cub, int x)
{
	t_img	*tex;
	int		y;
	int		texture_x;
	double	step;

	tex = get_wall_texture(cub);
	calculate_wall_x(cub);
	texture_x = (int)(cub->ray.wall_x * tex->width);
	if ((cub->ray.side == 0 && cub->ray.dir_x > 0)
		|| (cub->ray.side == 1 && cub->ray.dir_y < 0))
		texture_x = tex->width - texture_x - 1;
	if (cub->ray.line_height == 0)
		return ;
	step = (double)tex->height / (double)cub->ray.line_height;
	cub->ray.tex_pos = (cub->ray.draw_start - cub->win.height / 2
			+ cub->ray.line_height / 2) * step;
	y = cub->ray.draw_start;
	while (y <= cub->ray.draw_end)
	{
		cub->ray.tex_y = (int)cub->ray.tex_pos;
		update_ray_tex(cub, tex);
		put_pixel(cub, x, y, get_texture_pixel(tex, texture_x, cub->ray.tex_y));
		cub->ray.tex_pos += step;
		y++;
	}
}
