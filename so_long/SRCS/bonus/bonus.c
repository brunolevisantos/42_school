/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:48:47 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/01 08:33:12 by bde-seic         ###   ########.fr       */
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

void	get_enemy_start(t_data *data)
{
	int	i;
	int	line;

	srand(get_time()); //ver se muda pos inicial do enemy
	i = rand () % data->map.map_elem;
	line = rand () % data->map.map_lines;
	if (data->map.map[line][i] != '0')
		get_enemy_start(data);
	else
	{
		data->enemy.i = i;
		data->enemy.line = line;
		data->enemy.start = 1;
	}
}

void	get_enemy_pos(t_data *data)
{
	int	x;

	if (get_time() > data->enemy.t)
	{
		x = rand() % 4;
		if (x == 0 && check_enemy_next(data->enemy.line, data->enemy.i + 1))
			data->enemy.i++;
		else if (x == 1 && check_enemy_next(data->enemy.line, \
		data->enemy.i - 1))
			data->enemy.i--;
		else if (x == 2 && check_enemy_next(data->enemy.line + 1, \
		data->enemy.i))
			data->enemy.line++;
		else if (x == 3 && check_enemy_next(data->enemy.line - 1, \
		data->enemy.i))
			data->enemy.line--;
		data->enemy.t = get_time() + 400;
	}
}

void	get_enemy_img(t_data *data)
{
	static int	i;

	if (get_time() > data->enemy.t1)
	{
		data->enemy.img = &data->objects.enemy[i];
		i = (i + 1) % 4;
		data->enemy.t1 = get_time() + 400;
	}
}

void	bonus(t_data *data)
{
	if (data->stop_print == 0)
	{
		print_moves();
		if (data->enemy.start == 0)
			get_enemy_start(data);
		get_enemy_pos(data);
		get_enemy_img(data);
		draw_canva(data, data->enemy.img, data->enemy.i * 32, \
		data->enemy.line * 32);
	}
}
