/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:32:37 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/08 15:44:21 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_img	load_image(t_data *data, char *path)
{
	int		height;
	int		width;
	t_img	player;

	player = mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
//	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
	return (player);
}

int	render(t_data *data)
{
	// do_image(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data		data;
	t_player	player;

	data = initialize();
	player = load_image(&data, "./IMG/Owlet_Monster.xpm");
	//load_image(&data, "./IMG/Rock2.xpm");
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, ft_close, &data);
	mlx_loop(data.mlx_ptr);
}
