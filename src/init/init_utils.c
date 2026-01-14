/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:21:15 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/14 17:36:38 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_texture(t_cub *cub, t_img *texture, char *path)
{
	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	texture->ptr = mlx_xpm_file_to_image(cub->mlx,
		path, &texture->width, &texture->height);
	if (!texture->ptr)
		free_exit(EXIT_FAILURE, cub, FAIL_TEXTURE, NULL);
	texture->addr = mlx_get_data_addr(texture->ptr,
		&texture->bpp, &texture->line_len, &texture->endian);
}

void	load_all_textures(t_cub *cub)
{
	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	load_texture(cub, &cub->textures[TEX_NORTH], cub->map.no);
	load_texture(cub, &cub->textures[TEX_SOUTH], cub->map.so);
	load_texture(cub, &cub->textures[TEX_WEST], cub->map.we);
	load_texture(cub, &cub->textures[TEX_EAST], cub->map.ea);
}
