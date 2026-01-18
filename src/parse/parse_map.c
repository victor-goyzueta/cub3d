/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:20:00 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/18 21:51:49 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static int	update_sizes(t_cub *cub, int new_width, int new_height)
// {
// 	if (!cub)
// 		return (-1);
// 	if (new_width > cub->map.width)
// 		cub->map.width = new_width;
// 	cub->map.height = new_height;
// 	return (0);
// }

static char	*cpy_map(char *line, int *width)
{
	char	*cpy_line;

	if (!line || !width)
		return (NULL);
	cpy_line = NULL;
	cpy_line = line;
	if ((int)ft_strlen(cpy_line) > *width)
		*width = (int)ft_strlen(cpy_line);
	return (cpy_line);
}

void	parse_map(t_cub *cub)
{
	int		i;
	int		height;
	int		width;

	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	i = cub->map.start - 1;
	height = 0;
	while (cub->map.lines[(i + 1) + height])
		height++;
	cub->map.matrix = ft_calloc(sizeof(char *), (height + 1));
	if (!cub->map.matrix)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	height = 0;
	width = 0;
	while (cub->map.lines[++i])
	{
		cub->map.matrix[height] = cpy_map(ft_strdup(cub->map.lines[i]), &width);
		// cub->map.matrix[height] = ft_strdup(cub->map.lines[i]);
		// if (!cub->map.matrix[height])
		// 	free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
		// if (update_sizes(cub, (int)ft_strlen(cub->map.matrix[height]), height) == -1)
		// 	free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
		height++;
	}
	cub->map.width = width;
	cub->map.height = height;
}
