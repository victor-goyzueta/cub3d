/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 22:00:01 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/15 23:08:40 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**add_line(char **array, char *line, int count)
{
	char	**new;
	int		i;

	if (!array || !line)
		return (NULL);
	new = ft_calloc(sizeof(char *), (count + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new[i] = array[i];
		i++;
	}
	new[count] = line;
	new[count + 1] = NULL;
	if (array)
		free(array);
	return (new);
}

void	get_lines(t_cub *cub, char *file)
{
	char	*line;
	int		count;

	if (!cub || !file)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	cub->map.fd = open(file, O_RDONLY);
	if (cub->map.fd < 0)
		free_exit(EXIT_FAILURE, cub, OPEN_FD, NULL);
	line = NULL;
	line = get_next_line(cub->map.fd);
	if (!line)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	count = 0;
	while (line)
	{
		cub->map.lines = add_line(cub->map.lines, ft_strdup(line), count++);
		if (!cub->map.lines)
			free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, line);
		free(line);
		line = get_next_line(cub->map.fd);
	}
	if (close(cub->map.fd) != 0)
		free_exit(EXIT_FAILURE, cub, CLOSE_FD, NULL);
}
