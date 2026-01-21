/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:28:57 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/21 12:35:24 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray(t_cub *cub, int x)
{
	cub->ray.camera_x = 2.0 * x / cub->win.width - 1;
	cub->ray.dir_x = cub->player.dir_x
		+ cub->player.plane_x * cub->ray.camera_x;
	cub->ray.dir_y = cub->player.dir_y
		+ cub->player.plane_y * cub->ray.camera_x;
	cub->ray.map_x = (int)cub->player.pos_x;
	cub->ray.map_y = (int)cub->player.pos_y;
	calculate_delta(cub);
	calculate_step(cub);
}

static void	init_dda(t_cub *cub)
{
	int		hit;

	hit = 0;
	while (!hit)
	{
		if (cub->ray.sidedist_x < cub->ray.sidedist_y)
		{
			cub->ray.sidedist_x += cub->ray.delta_x;
			cub->ray.map_x += cub->ray.step_x;
			cub->ray.side = 0;
		}
		else
		{
			cub->ray.sidedist_y += cub->ray.delta_y;
			cub->ray.map_y += cub->ray.step_y;
			cub->ray.side = 1;
		}
		if (cub->ray.map_y >= 0 && cub->ray.map_y < cub->map.height
			&& cub->ray.map_x >= 0 && cub->ray.map_x < cub->map.width
			&& cub->map.matrix[cub->ray.map_y][cub->ray.map_x] != '0')
			hit = 1;
	}
}

static void	calculate_wall(t_cub *cub)
{
	if (cub->ray.side == 0)
	{
		cub->ray.wall_dist = (cub->ray.map_x - cub->player.pos_x
				+ (1 - cub->ray.step_x) / 2) / cub->ray.dir_x;
	}
	else
	{
		cub->ray.wall_dist = (cub->ray.map_y - cub->player.pos_y
				+ (1 - cub->ray.step_y) / 2) / cub->ray.dir_y;
	}
	if (cub->ray.wall_dist < 0.00001)
		cub->ray.wall_dist = 0.00001;
	cub->ray.line_height = (int)(cub->win.height / cub->ray.wall_dist);
	cub->ray.draw_start = -cub->ray.line_height / 2
		+ cub->win.height / 2;
	cub->ray.draw_end = cub->ray.line_height / 2
		+ cub->win.height / 2;
	if (cub->ray.draw_start < 0)
		cub->ray.draw_start = 0;
	if (cub->ray.draw_end >= cub->win.height)
		cub->ray.draw_end = cub->win.height - 1;
}

static void	draw_column(t_cub *cub, int x)
{
	int		y;

	y = 0;
	while (y < cub->ray.draw_start)
		put_pixel(cub, x, y++, cub->map.ceiling_color);
	draw_textured_column(cub, x);
	y = cub->ray.draw_end + 1;
	while (y < cub->win.height)
		put_pixel(cub, x, y++, cub->map.floor_color);
}

void	raycast(t_cub *cub)
{
	int	x;

	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	x = 0;
	while (x < cub->win.width)
	{
		init_ray(cub, x);
		init_dda(cub);
		calculate_wall(cub);
		draw_column(cub, x);
		x++;
	}
}
