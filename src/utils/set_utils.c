/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:58:30 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/15 20:33:04 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_images(t_cub *cub)
{
	int	i;

	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	cub->img.ptr = NULL;
	cub->img.addr = NULL;
	cub->img.bpp = 0;
	cub->img.line_len = 0;
	cub->img.endian = 0;
	cub->img.width = 0;
	cub->img.height = 0;
	i = 0;
	while (i < 4)
	{
		cub->textures[i].ptr = NULL;
		cub->textures[i].addr = NULL;
		cub->textures[i].bpp = 0;
		cub->textures[i].line_len = 0;
		cub->textures[i].endian = 0;
		cub->textures[i].width = 0;
		cub->textures[i].height = 0;
		i++;
	}
}

void	set_map(t_cub *cub)
{
	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	cub->map.matrix = NULL;
	cub->map.cpy_map = NULL;
	cub->map.file == NULL;
	cub->map.fd = -1;
	cub->map.line_count = 0;
	cub->map.start = -1;
	cub->map.width = 0;
	cub->map.height = 0;
	cub->map.no = NULL;
	cub->map.so = NULL;
	cub->map.we = NULL;
	cub->map.ea = NULL;
	cub->map.floor_color = -1;
	cub->map.ceiling_color = -1;
}

void	set_player(t_cub *cub)
{
	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	cub->player.pos_x = 0.0;
	cub->player.pos_y = 0.0;
	cub->player.dir_x = 0.0;
	cub->player.dir_y = 0.0;
	cub->player.plane_x = 0.0;
	cub->player.plane_y = 0.0;
	cub->player.move_x = 0;
	cub->player.move_y = 0;
	cub->player.rotate = 0;
}

void	set_raycast(t_cub *cub)
{
	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	cub->ray.camera_x = 0.0;
	cub->ray.dir_x = 0.0;
	cub->ray.dir_y = 0.0;
	cub->ray.map_x = 0;
	cub->ray.map_y = 0;
	cub->ray.step_x = 0;
	cub->ray.step_y = 0;
	cub->ray.sidedist_x = 0.0;
	cub->ray.sidedist_y = 0.0;
	cub->ray.delta_x = 0.0;
	cub->ray.delta_y = 0.0;
	cub->ray.wall_dist = 0.0;
	cub->ray.wall_x = 0.0;
	cub->ray.side = 0;
	cub->ray.line_height = 0;
	cub->ray.draw_start = 0;
	cub->ray.draw_end = 0;
}

void	set_keys(t_cub *cub)
{
	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	cub->keys.w = 0;
	cub->keys.a = 0;
	cub->keys.s = 0;
	cub->keys.d = 0;
	cub->keys.left = 0;
	cub->keys.right = 0;
}
