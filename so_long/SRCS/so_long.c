/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:32:37 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/23 13:54:36 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_img	*decide_img(char i)
{
	// if (i == 'P')
	// 	return (&data()->player.img_down);
	if (i == '1')
		return (&data()->objects.wall);
	if (i == '0' || i == 'P')
		return (&data()->objects.floor);
	if (i == 'C')
		return (&data()->objects.candy);
	if (i == 'E')
		return (&data()->objects.exit_no);
	return (0);
}

int	render(t_data *data)
{
	int	line;
	int	i;

	line = -1;
	while (data->map.map[++line])
	{
		i = -1;
		while (data->map.map[line][++i] != '\n' && data->map.map[line][i] != 0)
			draw_canva(data, decide_img('0'), 32 * i, 32 * line);
	}
	line = -1;
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

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{	
		if (map_checker(av[1]))
		{
			initialize();
			fill_obj(data());
			mlx_loop_hook(data()->mlx_ptr, render, data());
			mlx_hook(data()->win_ptr, KeyPress, KeyPressMask, handle_keypress, data());
			mlx_hook(data()->win_ptr, 17, 0, ft_close, data());
			mlx_loop(data()->mlx_ptr);
		}
	}
	else
		handle_msg("Invalid number of arguments.");
}
