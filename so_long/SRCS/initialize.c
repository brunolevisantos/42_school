/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:24:04 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/08 14:40:15 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_data	initialize(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		exit (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, W, H, "Hello world!");
	if (!data.win_ptr)
		exit (0);
	return (data);
}
