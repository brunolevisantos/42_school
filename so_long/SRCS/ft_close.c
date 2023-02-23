/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:23:52 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/23 16:43:26 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_close(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->canva.img);
	mlx_destroy_image(data->mlx_ptr, data->objects.img_up.img);
	mlx_destroy_image(data->mlx_ptr, data->objects.img_right.img);
	mlx_destroy_image(data->mlx_ptr, data->objects.img_down.img);
	mlx_destroy_image(data->mlx_ptr, data->objects.img_left.img);
	mlx_destroy_image(data->mlx_ptr, data->objects.wall.img);
	mlx_destroy_image(data->mlx_ptr, data->objects.candy.img);
	mlx_destroy_image(data->mlx_ptr, data->objects.exit_no.img);
	mlx_destroy_image(data->mlx_ptr, data->objects.exit_yes.img);
	mlx_destroy_image(data->mlx_ptr, data->objects.floor.img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit (0);
}
