/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:18:55 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/23 15:21:14 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_floor(t_data *data)
{
	int	line;
	int	i;

	line = -1;
	while (data->map.map[++line])
	{
		i = -1;
		while (data->map.map[line][++i] != '\n' && data->map.map[line][i] != 0)
			draw_canva(data, decide_img('0'), 32 * i, 32 * line);
	}
}
