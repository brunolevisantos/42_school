/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:18:55 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/24 16:29:11 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	draw_floor(t_data *data)
{
	int	line;
	int	i;

	line = -1;
	while (data->map.map[++line])
	{
		i = -1;
		while (data->map.map[line] && data->map.map[line][++i] != '\n' \
		&& data->map.map[line][i])
			draw_canva(data, decide_img('0'), 32 * i, 32 * line);
	}
}
