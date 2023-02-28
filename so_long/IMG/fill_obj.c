/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:34:23 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/28 15:33:17 by bde-seic         ###   ########.fr       */
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
	data->player.img = &data->objects.img_up;
	data->objects.exit_yes = load_image(data, "./IMG/exit_yes.xpm");
	data->objects.exit_no = load_image(data, "./IMG/exit_no.xpm");
	data->objects.exit = &data->objects.exit_no;
	data->objects.candy = load_image(data, "./IMG/Dude_Monster.xpm");
	data->objects.wall = load_image(data, "./IMG/Wall.xpm");
	data->objects.floor = load_image(data, "./IMG/Floor.xpm");
	data->objects.the_end = load_image(data, "./IMG/the_end.xpm");
	data->objects.enemy[0] = load_image(data, "./IMG/enemy/enemy0.xpm");
	data->objects.enemy[1] = load_image(data, "./IMG/enemy/enemy1.xpm");
	data->objects.enemy[2] = load_image(data, "./IMG/enemy/enemy2.xpm");
	data->objects.enemy[3] = load_image(data, "./IMG/enemy/enemy3.xpm");
	data->objects.game_over = load_image(data, "./IMG/Game_over.xpm");
}
