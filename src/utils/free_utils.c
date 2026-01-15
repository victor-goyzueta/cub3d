/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:45:19 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/15 21:20:03 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map(t_cub *cub)
{
	if (!cub)
		return ;
	if (cub->map.matrix)
		free_array(cub->map.matrix);
	if (cub->map.cpy_map)
		free_array(cub->map.cpy_map);
	if (cub->map.file)
		free_array(cub->map.file);
	if (cub->map.no)
		free(cub->map.no);
	if (cub->map.so)
		free(cub->map.so);
	if (cub->map.we)
		free(cub->map.ea);
	if (cub->map.ea)
		free(cub->map.ea);
	set_map(cub);
}

static void	free_images(t_cub *cub)
{
	if (!cub)
		return ;
	if (cub->textures[TEX_NORTH].ptr)
		mlx_destroy_image(cub->mlx, cub->textures[TEX_NORTH].ptr);
	if (cub->textures[TEX_SOUTH].ptr)
		mlx_destroy_image(cub->mlx, cub->textures[TEX_SOUTH].ptr);
	if (cub->textures[TEX_WEST].ptr)
		mlx_destroy_image(cub->mlx, cub->textures[TEX_WEST].ptr);
	if (cub->textures[TEX_EAST].ptr)
		mlx_destroy_image(cub->mlx, cub->textures[TEX_EAST].ptr);
	if (cub->img.ptr)
		mlx_destroy_image(cub->mlx, cub->img.ptr);
	set_images(cub);
}

static void	free_window(t_cub *cub)
{
	if (!cub)
		return ;
	if (cub->mlx && cub->win.win)
	{
		mlx_clear_window(cub->mlx, cub->win.win);
		mlx_destroy_window(cub->mlx, cub->win.win);
	}
	cub->win.win = NULL;
}

static void	free_all(t_cub *cub)
{
	if (!cub)
		return ;
	free_map(cub);
	free_images(cub);
	free_window(cub);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
	cub->mlx = NULL;
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
