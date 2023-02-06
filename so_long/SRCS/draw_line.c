/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:22:49 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/26 14:13:29 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_line(t_img *img, t_point start, t_point finish)
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