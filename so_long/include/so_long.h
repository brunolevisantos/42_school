/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:32:41 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/24 15:54:42 by bde-seic         ###   ########.fr       */
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

# include "../SRCS/utils/get_next_line/get_next_line.h"
# include "../SRCS/utils/ft_printf/ft_printf.h"
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_obj{
	t_img	wall;
	t_img	candy;
	t_img	*exit;
	t_img	exit_no;
	t_img	exit_yes;
	t_img	floor;
	t_img	img_right;
	t_img	img_down;
	t_img	img_left;
	t_img	img_up;
	t_img	the_end;
}	t_obj;

typedef struct s_player{
	t_img	*img;
	int		i;
	int		line;
}	t_player;

typedef struct s_map{
	char	**map;
	int		map_lines;
	int		map_elem;
	int		p;
	int		e;
	int		c;
	int		p_double;
	int		e_double;
	int		c_double;
}	t_map;

typedef struct s_data {
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		canva;
	t_obj		objects;
	t_player	player;
	t_map		map;
	int			moves;
}	t_data;

typedef struct s_point {
	char	value;
	int		i;
	int		line;
}	t_point;

void	initialize(void);
void	fill_obj(t_data *data);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, void *data);
int		handle_no_event(void *data);
int		handle_input(int keysym, t_data *data);
int		ft_close(t_data *data);
void	draw_canva(t_data *data, t_img *img, int x1, int y1);
char	**load_map_zico(char **map, int fd, int line_count);
int		elem_count(char *line);
int		line_count(char **map);
int		handle_msg(char *msg);
t_data	*data(void);
int		map_checker(char *map_path);
int		check_path(char	**map);
char	**map_copy(char **map);
int		map_free(char **map);
int		check_map_name(char *check_map_path);
int		render(t_data *data);
t_img	*decide_img(char i);
void	draw_floor(t_data *data);
void	rezise_img(t_img *img, double w, double h);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
void	*ft_calloc(size_t nelem, size_t elsize);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);

#endif
