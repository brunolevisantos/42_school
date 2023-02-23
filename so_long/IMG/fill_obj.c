/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:34:23 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/23 16:44:15 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_img	load_image(t_data *data, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(data->mlx_ptr, \
		path, &img.width, &img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	return (img);
}

void	fill_obj(t_data *data)
{
	data->objects.img_up = load_image(data, "./IMG/CAR/CarUp.xpm");
	data->objects.img_right = load_image(data, "./IMG/CAR/CarRight.xpm");
	data->objects.img_down = load_image(data, "./IMG/CAR/CarDown.xpm");
	data->objects.img_left = load_image(data, "./IMG/CAR/CarLeft.xpm");
	data->player.img = &data->objects.img_down;
	data->objects.exit_yes = load_image(data, "./IMG/Exit.xpm");
	data->objects.exit_no = load_image(data, "./IMG/No.xpm");
	data->objects.exit = &data->objects.exit_no;
	data->objects.candy = load_image(data, "./IMG/Dude_Monster.xpm");
	data->objects.wall = load_image(data, "./IMG/Wall.xpm");
	data->objects.floor = load_image(data, "./IMG/Floor.xpm");
}
