/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:17:40 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/23 15:27:01 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	render(t_data *data)
{
	int	line;
	int	i;

	line = -1;
	draw_floor(data);
	erase_obj(data, data->player.i, data->player.line);
	while (data->map.map[++line])
	{
		i = -1;
		while (data->map.map[line][++i] != '\n' && data->map.map[line][i] != 0)
			draw_canva(data, decide_img(data->map.map[line][i]), 32 * i, 32 * line);
	}
	draw_canva(data, &data->player.img_down, data->player.i * 32, data->player.line * 32);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->canva.img, 0, 0);
	return (0);
}
