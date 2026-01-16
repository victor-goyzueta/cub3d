/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:47:59 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/16 22:50:21 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_cub(t_cub *cub, char *file)
{
	if (!cub || !file)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	get_lines(cub, file);
	find_map_start(cub);
	parse_map(cub);
	//
}
