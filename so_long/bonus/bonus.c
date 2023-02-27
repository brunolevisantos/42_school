/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:48:47 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/27 23:26:18 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	bonus(t_data *data)
{
	static int	i;
	static int	line;
	static int	previous;
	
	previous = data->map.map[line][i];
	i = rand() % data->map.map_elem;
	line = rand() % data->map.map_lines;
	if (data->continue_print == 0)
	{
		print_moves();
		draw_canva(data, data->enemy, i * 32, line * 32);
		data->map.map[line][i] = 'N';
	}
	
}
