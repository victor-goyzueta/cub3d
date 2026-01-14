/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:12:11 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/14 18:28:01 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	validate_args(int argc, char *file)
{
	size_t	len;
	
	len = 0;
	if (argc != 2 || !file || !*file)
		ft_perror(USAGE);
	len = ft_strlen(file);
	if (ft_strncmp(file + (len - 4), ".cub", 4) != 0
		|| file[len - 5] == '/' || len < 5)
		ft_perror(NO_FORM);
}

static void	set_cub(t_cub *cub)
{
	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	cub->mlx = NULL;
	cub->win.win = NULL;
	cub->win.width = 0;
	cub->win.height = 0;
	set_images(cub);
	set_map(cub);
	set_player(cub);
	set_raycast(cub);
	set_keys(cub);
}

static void	init(t_cub *cub)
{
	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	cub->mlx = mlx_init();
	if (!cub->mlx)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	cub->win.width = WIDTH;
	cub->win.height = HEIGHT;
	load_all_textures(cub);
	cub->win.win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3d");
	if (!cub->win.win)
		free_exit(EXIT_FAILURE, cub, FAIL_MLX_WIN, NULL);
	cub->img.ptr = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->img.ptr)
		free_exit(EXIT_FAILURE, cub, FAIL_MLX_IMG, NULL);
	cub->img.addr = mlx_get_data_addr(cub->img.ptr,
		&cub->img.bpp, &cub->img.line_len, &cub->img.endian);
	mlx_clear_window(cub->mlx, cub->win.win);
}

static void	play(t_cub *cub)
{
	if (!cub)
		free_exit(EXIT_FAILURE, cub, FAIL_ALLOC, NULL);
	mlx_loop_hook(cub->mlx, render_frame, cub);
	mlx_hook(cub->win.win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->win.win, 3, 1L << 0, key_release, cub);
	mlx_hook(cub->win.win, 17, 1L << 0, handle_close, cub);
	mlx_loop(cub->mlx);
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	validate_args(argc, ++argv);
	set_cub(&cub);
	parse_cub(&cub, *argv);
	init(&cub);
	play(&cub);
}
