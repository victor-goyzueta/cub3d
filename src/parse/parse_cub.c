/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:47:59 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/16 00:03:29 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_map_start(t_cub *cub)
{
	int		i;
	int		j;

	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	i = 0;
	while (cub->map.lines[i])
	{
		if (parse_lines_identifier(map, lines[i]) == 1)
		{
			i++;
			continue ;
		}
		j = 0;
		while (is_spacetab(lines[i][j]))
			j++;
		if (lines[i][j] == '1' || lines[i][j] == '0'
				|| is_player_char(lines[i][j]))
		{
			cub->map.start = i;
			return ;
		}
		i++;
	}
	free_exit(EXIT_FAILURE, cub, NO_MAP, NULL);
}

void	parse_cub(t_cub *cub, char *file)
{
	int	i;

	if (!cub || !file)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	get_lines(cub, file);
	find_map_start(cub);
	//
}
