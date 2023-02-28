/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:25:06 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/28 14:34:47 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (color == -16777216)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *) dst = color;
}

int	my_mlx_pixel_get(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *) dst);
}

void	draw_canva(t_data *data, t_img *img, int x1, int y1)
{
	int	x;
	int	y;

	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
			my_mlx_pixel_put(&data->canva, x1 + x, y1 + y, \
			my_mlx_pixel_get(img, x, y));
	}
}

void	resize_img(t_img *img, double w, double h)
{
	int		x;
	int		y;
	double	i;
	double	j;

	y = -1;
	i = 0;
	data()->stop_print = 1;
	while (++y < h)
	{
		x = -1;
		j = 0;
		while (++x < w)
		{	
			my_mlx_pixel_put(&data()->canva, x, y, \
			my_mlx_pixel_get(img, j, i));
			j += (img->width / w);
		}
		i += (img->height / h);
	}
}
