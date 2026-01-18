/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 00:48:54 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/18 20:19:25 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_delta(t_cub *cub)
{
	if (cub->ray.dir_x == 0)
		cub->ray.delta_x = 1e30;
	else
		cub->ray.delta_x = fabs(1 / cub->ray.dir_x);
	if (cub->ray.dir_y == 0)
		cub->ray.delta_y = 1e30;
	else
		cub->ray.delta_y = fabs(1 / cub->ray.dir_y);
}

static void	calculate_step_x(t_cub *cub)
{
	if (cub->ray.dir_x < 0)
	{
		cub->ray.step_x = -1;
		cub->ray.sidedist_x = (cub->player.pos_x - cub->ray.map_x)
			* cub->ray.delta_x;
	}
	else
	{
		cub->ray.step_x = 1;
		cub->ray.sidedist_x = (cub->ray.map_x + 1.0 - cub->player.pos_x)
			* cub->ray.delta_x;
	}
}

static void	calculate_step_y(t_cub *cub)
{
	if (cub->ray.dir_y < 0)
	{
		cub->ray.step_y = -1;
		cub->ray.sidedist_y = (cub->player.pos_y - cub->ray.map_y)
			* cub->ray.delta_y;
	}
	else
	{
		cub->ray.step_y = 1;
		cub->ray.sidedist_y = (cub->ray.map_y + 1.0 - cub->player.pos_y)
			* cub->ray.delta_y;
	}
}

void	calculate_step(t_cub *cub)
{
	calculate_step_x(cub);
	calculate_step_y(cub);
}

void	put_pixel(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= cub->win.width || y >= cub->win.height)
		return ;
	dst = cub->img.addr
		+ (y * cub->img.line_len + (x * cub->img.bpp / 8));
	*(unsigned int *)dst = color;
}
