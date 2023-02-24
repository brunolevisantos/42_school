/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:17:40 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/24 16:18:21 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	print_moves(void)
{
	char	*movements;
	char	*message;
	char	*moves;

	message = 0;
	movements = " movements.";
	moves = ft_itoa(data()->moves);
	message = ft_strjoin(moves, movements);
	mlx_string_put(data()->mlx_ptr, \
	data()->win_ptr, 10, 20, WHITE_PIXEL, message);
	free (message);
}

int	render(t_data *data)
{
	int		line;
	int		i;

	line = -1;
	if (data->map.c == -1)
		rezise_img(&data->objects.the_end, data->canva.width, \
		data->canva.height);
	else
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
	print_moves();
	return (0);
}
