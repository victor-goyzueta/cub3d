/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:20:00 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/23 22:30:15 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static int	find_map_end(char **str)
{
	int		end;
	int		j;
	bool	found;

	if (!str || !*str)
		return (-1);
	end = 0;
	while (str[end])
	{
		ft_printf_fd(2, "%s", str[end]);
		j = 0;
		found = false;
		while (str[end][j])
		{
			if (str[end][j] == ' ' || str[end][j] == '\t'
				|| str[end][j] == 1 || str[end][j] == '0'
				|| is_player_char(str[end][j]))
				found = true;
			j++;
		}
		if (!found)
			return (end);
		end++;
	}
	return (end);
}

void	parse_map(t_cub *cub)
{
	int		i;
	int		height;
	int		width;

	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	i = cub->map.start;
	height = find_map_end(cub->map.lines + i);
	if (height == -1)
		free_exit(EXIT_FAILURE, cub, INV_MAP, NULL);
	ft_printf_fd(2, "%i\n", height);
	cub->map.matrix = ft_calloc(sizeof(char *), (height + 1));
	if (!cub->map.matrix)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	cub->map.height = height;
	height = 0;
	width = 0;
	while (cub->map.lines[i] && height <= cub->map.height)
	{
		cub->map.matrix[height] = cpy_map(ft_strdup(cub->map.lines[i]), &width);
		height++;
		i++;
	}
	cub->map.width = width;
}
