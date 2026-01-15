/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:47:59 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/15 20:40:13 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_lines(t_cub *cub, char *file)
{
	if (!cub || !file)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	cub->map.fd = open(file, O_RDONLY);
	if (cub->map.fd < 0)
		free_exit(EXIT_FAILURE, cub, OPEN_FD, NULL);
	//
	if (close(cub->map.fd) != 0)
		free_exit(EXIT_FAILURE, cub, CLOSE_FD, NULL);
}

void	parse_cub(t_cub *cub, char *file)
{
	int	i;
	
	if (!cub || !file)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	get_lines(cub, file);
	if (find_map_start(cub) == -1);
		free_exit(EXIT_FAILURE, cub, "Map not found", NULL);
}
