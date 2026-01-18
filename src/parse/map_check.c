/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:46:30 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/18 21:05:26 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_characters(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (!is_player_char(map->matrix[y][x])
				&& !is_spacetab(map->matrix[y][x])
				&& map->matrix[y][x] != '0' && map->matrix[y][x] != '1')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

int	validate_player(t_map *map, int *pos_x, int *pos_y)
{
	int		x;
	int		y;
	int		count;

	count = 0;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (is_player_char(map->matrix[y][x]))
			{
				count++;
				if (count == 1)
				{
					*pos_x = x;
					*pos_y = y;
				}
				else
					return (-1);
			}
		}
	}
	return (count);
}

static int	check_side_width(char **map, int i, int side)
{
	if (!map)
		return (-1);
	if (map[0][i] == '0' || is_player_char(map[0][i]))
		return (-1);
	if (is_spacetab(map[0][i])
		&& (side > 1 && (map[1][i] == '0'
		|| is_player_char(map[1][i]))))
		return (-1);
	if (map[side - 1][i] == '0'
		|| is_player_char(map[side - 1][i]))
		return (-1);
	if (is_spacetab(map[side - 1][i])
		&& (side > 1 && (map[side - 2][i] == '0'
		|| is_player_char(map[side - 2][i]))))
		return (-1);
	return (0);
}

static int	check_side_height(char **map, int i, int side)
{
	if (!map)
		return (-1);
	if (map[i][0] == '0' || is_player_char(map[i][0]))
		return (-1);
	if (is_spacetab(map[i][0])
		&& (side > 1 && (map[i][1] == '0'
		|| is_player_char(map[i][1]))))
		return (-1);
	if (map[i][side - 1] == '0'
		|| is_player_char(map[i][side - 1]))
		return (-1);
	if (is_spacetab(map[i][side - 1])
		&& (side > 1 && (map[i][side - 2] == '0'
		|| is_player_char(map[i][side - 2]))))
		return (-1);
	return (0);
}

int	check_map_borders(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (check_side_width(map->matrix, i, map->height) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i > map->height)
	{
		if (check_side_height(map->matrix, i, map->width) != 0)
			return (-1);
		i++;
	}
	return (0);
}
