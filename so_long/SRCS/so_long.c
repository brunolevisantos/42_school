/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:32:37 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/08 14:34:22 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	do_image(t_data *data)
{
	int	height;
	int	width;

	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./IMG/Owlet_Monster.xpm", &width, &height);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	do_image(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, W / 2, H / 2);
	return (0);
}

int	main(void)
{
	t_data	data;

	data = initialize();
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, ft_close, &data);
	mlx_loop(data.mlx_ptr);
}
