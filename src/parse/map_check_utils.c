/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:58:50 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/18 20:51:51 by vgoyzuet         ###   ########.fr       */
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

void	flood_fill(t_cub *cub, int y, int x, int *error)
{
	if (!error)
		return ;
	if (y < 0 || y >= cub->map.height || x < 0 || x >= cub->map.width)
	{
		*error = 2;
		return ;
	}
	if (cub->map.cpy_map[y][x] == ' ' || cub->map.cpy_map[y][x] == '\0')
	{
		*error = 1;
		return ;
	}
	if (cub->map.cpy_map[y][x] == '1' || cub->map.cpy_map[y][x] == 'F')
		return ;
	cub->map.cpy_map[y][x] = 'F';
	flood_fill(cub, y + 1, x, error);
	flood_fill(cub, y - 1, x, error);
	flood_fill(cub, y, x + 1, error);
	flood_fill(cub, y, x - 1, error);
}
