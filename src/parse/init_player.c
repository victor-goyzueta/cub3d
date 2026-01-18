/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 21:06:06 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/18 21:07:09 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player_north_south(t_player *player)
{
	if (player->dir == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (player->dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else
		return ;
}

static void	init_player_west_east(t_player *player)
{
	if (player->dir == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (player->dir == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else
		return ;
}

static void	init_player_direction(t_cub *cub)
{
	init_player_north_south(&cub->player);
	init_player_west_east(&cub->player);
}

void	init_player(t_cub *cub)
{
	int		x;
	int		y;
	int		count;

	count = validate_player(cub->map, &x, &y);
	if (count != 1)
		free_exit(EXIT_FAILURE, cub, NO_PLAYER, NULL);
	cub->player.pos_x = x + 0.5;
	cub->player.pos_y = y + 0.5;
	cub->player.dir = cub->map.matrix[y][x];
	cub->map.matrix[y][x] = '0';
	init_player_direction(cub);
}
