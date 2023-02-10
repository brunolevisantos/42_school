/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:32:41 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/08 15:32:31 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define W 640
# define H 480
# define RED_PIXEL 0x00FF0000
# define GREEN_PIXEL 0x0000FF00
# define BLUE_PIXEL 0x000000FF
# define WHITE_PIXEL 0x00FFFFFF
# define MLX_ERROR 1 

# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_addr{
	char	*addrplayer;
	char	*addrwall;
	char	*addrcandy;
	char	*exit;
}	t_addr;

typedef struct s_obj{
	t_img	player;
	t_img	wall;
	t_img	candy;
	t_img	exit;
}	t_obj;

typedef struct s_player{
	t_img	img;
	int		x;
	int		y;
}	t_player;

typedef struct s_img {
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	t_obj	objects;
}	t_data;

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

void	draw_line(t_img *img, t_point start, t_point finish);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, void *data);
int		handle_no_event(void *data);
int		handle_input(int keysym, t_data *data);
int		ft_close(t_data *data);
t_data	initialize(void);

#endif
