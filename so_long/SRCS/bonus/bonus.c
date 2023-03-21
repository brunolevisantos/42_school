/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:48:47 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/17 13:49:23 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_enemy_next(int line, int i)
{
	if (data()->map.map[line][i] == '1')
		return (0);
	else
		return (1);
}

void	get_enemy_start(t_data *data, int n)
{
	int	i;
	int	line;

	srand(rand () % get_time());
	i = rand () % data->map.map_elem;
	line = rand () % data->map.map_lines;
	if (data->map.map[line][i] != '0')
		get_enemy_start(data, n);
	else
	{
		data->enemy[n].i = i;
		data->enemy[n].line = line;
		data->enemy[n].start = 1;
	}
}

void	get_enemy_pos(t_data *data, int n)
{
	int	x;

	if (get_time() > data->enemy[n].t)
	{
		x = rand() % 4;
		if (x == 0 && check_enemy_next(data->enemy[n].line, \
		data->enemy[n].i + 1))
			data->enemy[n].i++;
		else if (x == 1 && check_enemy_next(data->enemy[n].line, \
		data->enemy[n].i - 1))
			data->enemy[n].i--;
		else if (x == 2 && check_enemy_next(data->enemy[n].line + 1, \
		data->enemy[n].i))
			data->enemy[n].line++;
		else if (x == 3 && check_enemy_next(data->enemy[n].line - 1, \
		data->enemy[n].i))
			data->enemy[n].line--;
		data->enemy[n].t = get_time() + 400;
	}
}

void	get_enemy_img(t_data *data, int n)
{
	static int	i;

	if (get_time() > data->enemy[n].t1)
	{
		data->enemy[n].img = &data->objects.enemy[i];
		i = (i + 1) % 4;
		data->enemy[n].t1 = get_time() + 200;
	}
}

void	bonus(t_data *data)
{
	int	n;

	n = 0;
	if (data->stop_print == 0)
	{
		print_moves();
		while (n < 7)
		{
			if (data->enemy[n].start == 0)
				get_enemy_start(data, n);
			get_enemy_pos(data, n);
			get_enemy_img(data, n);
			draw_canva(data, data->enemy[n].img, data->enemy[n].i * 32, \
			data->enemy[n].line * 32);
			n++;
		}
	}
}
