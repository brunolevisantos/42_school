/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:32:34 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/01 10:47:44 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_next(int line, int i)
{
	if (data()->map.map[line][i] == 'E' && data()->map.c == 0)
		data()->map.c--;
	if (data()->map.map[line][i] == 'C')
	{	
		data()->map.map[line][i] = '0';
		if (!--data()->map.c)
			data()->objects.exit = &data()->objects.exit_yes;
	}
	if (data()->map.map[line][i] != '1')
		return (1);
	return (0);
}

int	handle_lateral(int keysym, t_data *data)
{
	if (keysym == XK_Left || keysym == XK_a)
	{
		data->moves++;
		data->player.img = &data->objects.img_left;
		if (check_next(data->player.line, data->player.i - 1))
			data->player.i--;
	}
	if (keysym == XK_Right || keysym == XK_d)
	{
		data->moves++;
		data->player.img = &data->objects.img_right;
		if (check_next(data->player.line, data->player.i + 1))
			data->player.i++;
	}
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_close(data);
	if (keysym == XK_Down || keysym == XK_s)
	{
		data->moves++;
		data->player.img = &data->objects.img_down;
		if (check_next(data->player.line + 1, data->player.i))
			data->player.line++;
	}
	if (keysym == XK_Up || keysym == XK_w)
	{
		data->moves++;
		data->player.img = &data->objects.img_up;
		if (check_next(data->player.line - 1, data->player.i))
			data->player.line--;
	}
	handle_lateral(keysym, data);
	return (0);
}
