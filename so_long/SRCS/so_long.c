/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:32:37 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/17 13:39:06 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_img	load_image(t_data *data, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(data->mlx_ptr, path, &img.width, &img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	return (img);
}

void	fill_obj(t_data *data)
{
	data->player.img_up = load_image(data, "./IMG/CAR/CarUp.xpm");
	data->player.img_right = load_image(data, "./IMG/CAR/CarRight.xpm");
	data->player.img_down = load_image(data, "./IMG/CAR/CarDown.xpm");
	data->player.img_left = load_image(data, "./IMG/CAR/CarLeft.xpm");
	data->objects.exit = load_image(data, "./IMG/Exit.xpm");
	data->objects.no = load_image(data, "./IMG/No.xpm");
	data->objects.candy = load_image(data, "./IMG/Dude_Monster.xpm");
	data->objects.wall = load_image(data, "./IMG/Wall.xpm");
	data->objects.floor = load_image(data, "./IMG/Floor.xpm");
}

int	render(t_data *data)
{
	draw_canva(data, &data->player.img_down, W / 2, H / 2);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->canva.img, 0, 0);
	return (0);
}

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

int	main(void)
{
	initialize();
	data()->player.i = 100; //nao deve ser preciso depois
	data()->player.line = 100; //nao deve ser preciso depois
	if (map_checker())
	{
		fill_obj(data());
		mlx_loop_hook(data()->mlx_ptr, render, data());
		mlx_hook(data()->win_ptr, KeyPress, KeyPressMask, handle_keypress, data());
		mlx_hook(data()->win_ptr, 17, 0, ft_close, data());
		mlx_loop(data()->mlx_ptr);
	}
}
