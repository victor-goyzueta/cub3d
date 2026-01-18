/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:47:59 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/18 21:55:52 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	validate_identifiers(t_cub *cub)
{
	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	if (!cub->map.no || !cub->map.so
		|| !cub->map.we || !cub->map.ea)
		free_exit(EXIT_FAILURE, cub, "No textures", NULL);
	if (cub->map.floor_color == -1 || cub->map.ceiling_color == -1)
		free_exit(EXIT_FAILURE, cub, "No colors", NULL);
}

static void	padding_rows(t_cub *cub)
{
	int		y;
	int		len;
	char	*row;

	y = 0;
	while (y < cub->map.height)
	{
		if (!cub->map.matrix[y])
			free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
		len = ft_strlen(cub->map.matrix[y]);
		if (len < cub->map.width)
		{
			row = ft_calloc(sizeof(char), cub->map.width + 1);
			if (!row)
				free_exit(EXIT_FAILURE, cub, "Malloc error in padding", NULL);
			row = ft_memset(row, ' ', cub->map.width);
			row = ft_memcpy(row, cub->map.matrix[y], len);
			row[cub->map.width] = '\0';
			free(cub->map.matrix[y]);
			cub->map.matrix[y] = row;
		}
		y++;
	}
}

static void	map_check(t_cub *cub)
{
	int		pos_x;
	int		pos_y;
	int		error;

	if (validate_characters(&cub->map) == -1)
		free_exit(EXIT_FAILURE, cub, INV_CHAR, NULL);
	if (validate_player(&cub->map, &pos_x, &pos_y) == -1)
		free_exit(EXIT_FAILURE, cub, INV_PLAYER, NULL);
	if (check_map_borders(&cub->map) == -1)
		free_exit(EXIT_FAILURE, cub, OPEN_BORDERS, NULL);
	cub->map.cpy_map = dup_map(cub->map.matrix, cub->map.height);
	if (!cub->map.cpy_map)
		free_exit(EXIT_FAILURE, cub, FAIL_CPY_MAP, NULL);
	error = 0;
	flood_fill(cub, pos_y, pos_x, &error);
	if (error)
		free_exit(EXIT_FAILURE, cub, OPEN_MAP, NULL);
}

void	parse_cub(t_cub *cub, char *file)
{
	if (!cub || !file)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	get_lines(cub, file);
	find_map_start(cub);
	parse_map(cub);
	validate_identifiers(cub);
	padding_rows(cub);
	print_data(cub->map); //delete
	map_check(cub);
	init_player(cub);
}
