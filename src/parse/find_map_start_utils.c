/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_start_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:48:48 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/21 12:32:58 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_path(char *line)
{
	char	*path;

	path = NULL;
	path = ft_strtrim(line, "\t\n\v\f\r ");
	if (!path)
		return (NULL);
	else if (!*path)
		return (free(path), NULL);
	return (path);
}

static int	parse_value(char **str)
{
	int		value;

	value = 0;
	if (**str == '+')
		(*str)++;
	if (!ft_isdigit(**str))
		return (-1);
	while (ft_isdigit(**str))
	{
		value = value * 10 + (**str - '0');
		(*str)++;
	}
	if (value < 0 || value > 255)
		return (-1);
	return (value);
}

int	parse_color(char *str)
{
	int		r;
	int		g;
	int		b;

	if (!str)
		return (-1);
	while (*str == ' ' || *str == '\t')
		str++;
	r = parse_value(&str);
	if (r == -1 || *str != ',')
		return (-1);
	str++;
	g = parse_value(&str);
	if (g == -1 || *str != ',')
		return (-1);
	str++;
	b = parse_value(&str);
	if (b == -1)
		return (-1);
	while (is_spacetab(*str))
		str++;
	if (*str != '\0')
		return (-2);
	return ((r << 16) | (g << 8) | b);
}
