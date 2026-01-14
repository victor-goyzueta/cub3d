/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:57:12 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/14 19:58:44 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_walkable(t_map *map, double x, double y)
{
	int		map_x;
	int		map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0
		|| map_x >= map->width
		|| map_y >= map->height)
		return (false);
	if (map->matrix[map_y][map_x] != '0')
		return (false);
	return (true);
}
