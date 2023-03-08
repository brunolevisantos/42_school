/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:17:40 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/08 14:46:10 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_finnish(t_data *data)
{
	int	n;

	n = 0;
	if (data->map.c == -1)
	{
		resize_img(&data->objects.the_end, data->canva.width, \
		data->canva.height);
		data->stop_print = 1;
	}
	while (n < 7)
	{
		if ((data->player.i == data->enemy[n].i) && \
		(data->player.line == data->enemy[n].line))
		{
			resize_img(&data->objects.game_over, data->canva.width, \
			data->canva.height);
			data->stop_print = 1;
		}
		n++;
	}
}

int	render(t_data *data)
{
	int		line;
	int		i;

	line = -1;
	check_finnish(data);
	if (data->stop_print == 0)
	{
		draw_floor(data);
		while (data->map.map[++line])
		{
			i = -1;
			while (data->map.map[line][++i] != '\n' && \
			data->map.map[line][i] != 0)
				draw_canva(data, decide_img(data->map.map[line][i]), 32 * i, \
				32 * line);
		}
		draw_canva(data, data->player.img, data->player.i * 32, \
		data->player.line * 32);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->canva.img, 0, 0);
	bonus(data);
	return (0);
}
