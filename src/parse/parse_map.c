/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:20:00 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/26 00:41:38 by vgoyzuet         ###   ########.fr       */
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
		j = 0;
		found = false;
		while (str[end][j])
		{
			if (str[end][j] == '1' || str[end][j] == '0'
				|| str[end][j] == '\t' || str[end][j] == ' '
				|| is_player_char(str[end][j]))
				found = true;
			j++;
		}
		if (!found)
			break ;
		end++;
	}
	return (end);
}

bool	has_more_lines(char **str)
{
	int	i;
	int	j;

	if (!str || !*str)
		return (false);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!is_spacetab(str[i][j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
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
	if (height == -1 || has_more_lines(cub->map.lines + (cub->map.start + height)))
		free_exit(EXIT_FAILURE, cub, INV_MAP, NULL);
	cub->map.matrix = ft_calloc(sizeof(char *), (height + 1));
	if (!cub->map.matrix)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	cub->map.height = height;
	height = 0;
	width = 0;
	while (cub->map.lines[i] && height < cub->map.height)
	{
		cub->map.matrix[height] = cpy_map(ft_strdup(cub->map.lines[i]), &width);
		height++;
		i++;
	}
	cub->map.matrix[height] = NULL;
	cub->map.width = width;
}
