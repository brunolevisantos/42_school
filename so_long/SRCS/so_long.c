/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:32:37 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/15 15:09:41 by bde-seic         ###   ########.fr       */
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
	data->player.img_player = load_image(data, "./IMG/Owlet_Monster.xpm");
	data->objects.exit = load_image(data, "./IMG/Pink_Monster.xpm");
	data->objects.candy = load_image(data, "./IMG/Rock2.xpm");
	data->objects.wall = load_image(data, "./IMG/Dude_Monster.xpm");
}

int	render(t_data *data)
{
	draw_canva(data, &data->player.img_player, W / 2, H / 2);
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
	data()->player.x = 100; //nao deve ser preciso depois
	data()->player.y = 100; //nao deve ser preciso depois
	fill_obj(&data);
	mlx_loop_hook(data()->mlx_ptr, render, &data);
	mlx_hook(data()->win_ptr, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_hook(data()->win_ptr, 17, 0, ft_close, &data);
	mlx_loop(data()->mlx_ptr);
}
