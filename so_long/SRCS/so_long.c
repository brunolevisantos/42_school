/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:32:37 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/23 15:39:14 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_data *img, t_point start, t_point finish)
{
	double	m;
	int		i;

	i = 0;
	m = (finish.y - start.y) / (finish.x - start.x);
	if (finish.x > start.x)
	{
		while (i <= finish.x - start.x)
		{
			my_mlx_pixel_put(img, start.x + i, (m * i) + (double)start.y, 0x00FFFFFF);
			i++;
		}	
	}
	else
	{
		while (i >= finish.x - start.x)
		{
			my_mlx_pixel_put(img, start.x + i, (m * i) + (double)start.y, 0x00FFFFFF);
			i--;
		}	
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_point a;
	t_point	b;
	t_point c;
	t_point d;
	t_point e;
	t_point f;

	a.x = 800;
	a.y = 5;
	b.x = 1120;
	b.y = 5;
	c.x = 1365;
	c.y = 255;
	d.x = 1120;
	d.y = 505;
	e.x = 800;
	e.y = 505;
	f.x = 555;
	f.y = 255;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, W, H, "Hello world!");
	img.img = mlx_new_image(mlx, W, H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
 	draw_line(&img, a, b);
	draw_line(&img, b, c);
	draw_line(&img, c, d);
	draw_line(&img, d, e);
	draw_line(&img, e, f);
	draw_line(&img, f, a);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
