/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:45:19 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/15 01:29:36 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_all(t_cub *cub)
{
	//
}

void	free_exit(int EXIT, t_cub *cub, char *message, char **cur)
{
	if (cub->mlx && cub->win->new)
		mlx_loop_end(cub->win->new);
	free_all(cub);
	if (cur)
		free_array(cur);
	if (EXIT == EXIT_SUCCESS)
	{
		if (message)
			ft_printf(message);
		exit(EXIT);
	}
	else
		ft_perror(message);
}
