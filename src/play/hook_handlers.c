/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:32:44 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/14 18:45:20 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	close_program(t_cub *cub)
{
	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	free_exit(EXIT_SUCCESS, cub, CLOSE_WIN, NULL);
}

int	render_frame(t_cub *cub)
{
	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	update_player(cub);
	raycast(cub);
	mlx_put_image_to_window(cub->mlx, cub->win.win,
		cub->img.ptr, 0, 0);
	return (0);
}

int	key_press(int k, t_cub *cub)
{
	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	if (k == W)
		cub->keys.w = 1;
	else if (k == A)
		cub->keys.a = 1;
	else if (k == S)
		cub->keys.s = 1;
	else if (k == D)
		cub->keys.d = 1;
	else if (k == LEFT)
		cub->keys.left = 1;
	else if (k == RIGHT)
		cub->keys.right = 1;
	else if (k == ESC)
		close_program(cub);
	return (0);
}

int	key_release(int k, t_cub *cub)
{
	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	if (k == W)
		cub->keys.w = 0;
	else if (k == A)
		cub->keys.a = 0;
	else if (k == S)
		cub->keys.s = 0;
	else if (k == D)
		cub->keys.d = 0;
	else if (k == LEFT)
		cub->keys.left = 0;
	else if (k == RIGHT)
		cub->keys.right = 0;
	return (0);
}

int	handle_close(t_cub *cub)
{
	close_program(cub);
	return (0);
}
