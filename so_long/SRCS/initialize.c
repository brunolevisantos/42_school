/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:24:04 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/17 16:15:43 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	initialize(void)
{
	data()->mlx_ptr = mlx_init();
	if (!data()->mlx_ptr)
		exit (0);
	(data())->win_ptr = mlx_new_window(data()->mlx_ptr, \
		32 * (data()->map.map_elem + 1), 32 * (data()->map.map_lines + 1), "Carnage!");
	if (!data()->win_ptr)
		exit (0);
	(data())->canva.img = mlx_new_image(data()->mlx_ptr, \
		32 * (data()->map.map_elem + 1), 32 * (data()->map.map_lines + 1));
	(data())->canva.addr = mlx_get_data_addr(data()->canva.img, \
	&data()->canva.bpp, &data()->canva.line_len, &data()->canva.endian);
}
