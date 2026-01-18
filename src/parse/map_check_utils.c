/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:58:50 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/18 21:01:17 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**dup_map(char **src, int height)
{
	char	**copy;
	int		i;

	copy = ft_calloc(sizeof(char *), (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(src[i]);
		if (!copy)
			break ;
		i++;
	}
	if (i < height)
	{
		while (--i > 0)
			free(copy[i - 1]);
		free(copy);
		return (NULL);
	}
	copy[height] = NULL;
	return (copy);
}

void	flood_fill(t_map map, int y, int x, int *error)
{
	if (*error)
		return ;
	if (y < 0 || y >= map.height || x < 0 || x >= map.width)
	{
		*error = 1;
		return ;
	}
	if (map.cpy_map[y][x] == ' ' || map.cpy_map[y][x] == '\0')
	{
		*error = 1;
		return ;
	}
	if (map.cpy_map[y][x] == '1' || map.cpy_map[y][x] == 'F')
		return ;
	map.cpy_map[y][x] = 'F';
	flood_fill(map, y + 1, x, error);
	flood_fill(map, y - 1, x, error);
	flood_fill(map, y, x + 1, error);
	flood_fill(map, y, x - 1, error);
}
