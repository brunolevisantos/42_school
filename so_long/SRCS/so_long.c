/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:32:37 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/11 13:27:19 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*load_image(t_data *data, char *path)
{
	int		height;
	int		width;
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
//	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
	return (img);
}

t_obj	fill_obj(t_data *data, t_addr address)
{
	t_obj	objects;

	objects.player = load_image(data, address.addrplayer);
	objects.wall = load_image(data, address.addrwall);
	objects.candy = load_image(data, address.addrcandy);
	objects.exit = load_image(data, address.addrexit);
	return (objects);
}

t_addr	fill_addr(void)
{
	t_addr address;
	//em vez de fazer funcao, por as addresses no .h
	address.addrplayer = "./IMG/Owlet_Monster.xpm";
	address.addrwall = "./IMG/...";
	address.addrcandy = "./IMG/...";
	address.addrexit = "./IMG/...";
	return (address);
}

int	render(t_data *data)
{	
	//put objects to image
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 10, 10);
	return (0);
}

int	main(void)
{
	t_data	data;
	t_obj	objects;

	data = initialize();
	objects = fill_obj(&data, fill_addr());
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, ft_close, &data);
	mlx_loop(data.mlx_ptr);
}
