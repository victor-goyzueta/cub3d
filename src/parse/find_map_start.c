/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:18:26 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/18 20:40:54 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_texture_north_and_south(t_cub *cub, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (cub->map.no)
			free_exit(EXIT_FAILURE, cub, DUP_NO, NULL);
		cub->map.no = get_path(line + 3);
		if (!cub.map.no)
			free_exit(EXIT_FAILURE, cub, INV_PATH, NULL);
		if (access(cub->map.no, R_OK) != 0)
			free_exit(EXIT_FAILURE, cub, NO_TEXT, NULL);
		return (1);
	}
	if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (cub->map.so)
			free_exit(EXIT_FAILURE, cub, DUP_SO, NULL);
		cub->map.so = get_path(line + 3);
		if (!cub.map.so)
			free_exit(EXIT_FAILURE, cub, INV_PATH, NULL);
		if (access(cub->map.so, R_OK) != 0)
			free_exit(EXIT_FAILURE, cub, NO_TEXT, NULL);
		return (1);
	}
	return (0);
}

static int	parse_texture_west_and_east(t_cub *cub, char *line)
{
	if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (cub->map.we)
			free_exit(EXIT_FAILURE, cub, DUP_WE, NULL);
		cub->map.we = get_path(line + 3);
		if (!cub.map.we)
			free_exit(EXIT_FAILURE, cub, INV_PATH, NULL);
		if (access(cub->map.we, R_OK) != 0)
			free_exit(EXIT_FAILURE, cub, NO_TEXT, NULL);
		return (1);
	}
	if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (cub->map.ea)
			free_exit(EXIT_FAILURE, cub, DUP_EA, NULL);
		cub->map.ea = get_path(line + 3);
		if (!cub.map.ea)
			free_exit(EXIT_FAILURE, cub, INV_PATH, NULL);
		if (access(cub->map.ea, R_OK) != 0)
			free_exit(EXIT_FAILURE, cub, NO_TEXT, NULL);
		return (1);
	}
	return (0);
}

static int	parse_floor_and_ceiling(t_cub *cub, char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (cub->map.floor_color != -1)
			free_exit(EXIT_FAILURE, cub, DUP_FLOOR, NULL);
		cub->map.floor_color = parse_color(line + 2);
		if (cub->map.floor_color == -1)
			free_exit(EXIT_FAILURE, cub, INV_FLOOR, NULL);
		if (cub->map.floor_color == -2)
			free_exit(EXIT_FAILURE, cub, INV_VALOR, NULL);
		return (1);
	}
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (cub->map.ceiling_color != -1)
			free_exit(EXIT_FAILURE, cub, DUP_CEILING, NULL);
		cub->map.ceiling_color = parse_color(line + 2);
		if (cub->map.ceiling_color == -1)
			free_exit(EXIT_FAILURE, cub, INV_CEILING, NULL);
		if (cub->map.ceiling_color == -2)
			free_exit(EXIT_FAILURE, cub, INV_VALOR, NULL);
		return (1);
	}
	return (0);
}

static bool	has_lines_identifier(t_cub *cub, char *line)
{
	if (!cub || !line)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	if (parse_texture_north_and_south(cub, line))
		return (true);
	if (parse_texture_west_and_east(cub, line))
		return (true);
	if (parse_floor_and_ceiling(cub, line))
		return (true);
	return (false);
}

void	find_map_start(t_cub *cub)
{
	int		i;
	int		j;

	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	i = 0;
	while (cub->map.lines[i])
	{
		if (has_lines_identifier(cub, lines[i]) == false)
		{
			j = 0;
			while (is_spacetab(lines[i][j]))
				j++;
			if (lines[i][j] == '1' || lines[i][j] == '0'
					|| is_player_char(lines[i][j]))
			{
				cub->map.start = i;
				return ;
			}
		}
		i++;
	}
	free_exit(EXIT_FAILURE, cub, NO_MAP, NULL);
}
