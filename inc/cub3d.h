/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:47:46 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/22 14:31:52 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <string.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define USAGE			"Usage: ./cub3d [*.cub]"
# define NO_FORM		"Invalid map format"
# define FAIL_ALLOC		"Failed memory allocation"
# define FAIL_TEXTURE	"Failure load texture"
# define FAIL_MLX_WIN	"mlx_init_window failed"
# define FAIL_MLX_IMG	"mlx_new_image failed"
# define CLOSE_WIN		"Closed window\n"
# define OPEN_FD		"Open fd"
# define CLOSE_FD		"Close fd"
# define NO_MAP			"Map not found"
# define DUP_NO			"Duplicate NO texture"
# define DUP_SO			"Duplicate SO texture"
# define DUP_WE			"Duplicate WE texture"
# define DUP_EA			"Duplicate EA texture"
# define DUP_FLOOR		"Duplicate floor color"
# define INV_FLOOR		"Invalid floor color"
# define DUP_CEILING	"Duplicate ceiling color"
# define INV_CEILING	"Invalid ceiling color"
# define INV_PATH		"Invalid texture path"
# define NO_TEXT		"Texture file not found"
# define INV_VALOR		"Please enter a valid value to floor and ceiling color"
# define INV_CHAR		"Invalid characters"
# define INV_PLAYER		"Invalid player"
# define OPEN_BORDERS	"Map has open borders"
# define FAIL_CPY_MAP	"Copy map to check failed"
# define OPEN_MAP		"Map is not closed"
# define NO_PLAYER		"Map must contain one player"
# define INV_MAP		"Invalid map"
# define STACKOF		"Very large map, may cause stack overflow"

# define WIDTH		1280
# define HEIGHT		720
# define MAX_LOOP	4242

# define W	119
# define A	97
# define S	115
# define D	100

# define LEFT	65361
# define RIGHT	65363
# define ESC	65307

# define MOVE_SPEED 0.02
# define ROT_SPEED  0.01

# define TEX_NORTH 0
# define TEX_SOUTH 1
# define TEX_EAST  2
# define TEX_WEST  3

typedef struct s_window
{
	void	*win;
	int		width;
	int		height;
}	t_win;

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_map
{
	char	**matrix;
	char	**cpy_map;
	char	**lines;
	int		fd;
	int		line_count;
	int		start;
	int		width;
	int		height;

	char	*no;
	char	*so;
	char	*we;
	char	*ea;

	int		floor_color;
	int		ceiling_color;
}	t_map;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		move_x;
	int		move_y;
	int		rotate;
	char	dir;
}	t_player;

typedef struct s_raycast
{
	double		camera_x;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	double		sidedist_x;
	double		sidedist_y;
	double		delta_x;
	double		delta_y;
	double		wall_dist;
	double		tex_pos;
	int			tex_y;
	double		wall_x;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_ray;

typedef struct s_keys
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
}	t_keys;

typedef struct s_cub3d
{
	void		*mlx;
	t_win		win;
	t_img		img;
	t_img		textures[4];
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_keys		keys;
}	t_cub;

/*set_utils*/
void	set_images(t_cub *cub);
void	set_map(t_cub *cub);
void	set_player(t_cub *cub);
void	set_raycast(t_cub *cub);
void	set_keys(t_cub *cub);

/*init_utils*/
void	load_all_textures(t_cub *cub);

/*parse*/
void	parse_cub(t_cub *cub, char *file);
void	get_lines(t_cub *cub, char *file);
void	find_map_start(t_cub *cub);
void	parse_map(t_cub *cub);
void	init_player(t_cub *cub);

/*find_map_start_utils*/
char	*get_path(char *line);
int		parse_color(char *str);

/*map_check*/
int		validate_characters(t_map *map);
int		validate_player(t_map *map, int *pos_x, int *pos_y);
int		check_map_borders(t_map *map);

/*map_check_utils*/
char	**dup_map(char **src, int height);
void	flood_fill(t_cub *cub, int y, int x, int *error);

/*play*/
int		render_frame(t_cub *cub);
int		key_press(int k, t_cub *cub);
int		key_release(int k, t_cub *cub);
int		handle_close(t_cub *cub);

/*render_frame*/
void	update_player(t_cub *cub);
void	raycast(t_cub *cub);

/*raycast_utils*/
void	calculate_delta(t_cub *cub);
void	calculate_step(t_cub *cub);
void	put_pixel(t_cub *cub, int x, int y, int color);
void	draw_textured_column(t_cub *cub, int x);

/*move_player*/
void	move_forward(t_cub *cub);
void	move_backward(t_cub *cub);
void	move_left(t_cub *cub);
void	move_right(t_cub *cub);

/*bool_utils*/
bool	is_spacetab(int c);
bool	is_player_char(int c);
bool	is_walkable(t_map *map, double x, double y);

/*free_utils*/
void	free_exit(int EXIT, t_cub *cub, char *message, char *cur);

#endif
