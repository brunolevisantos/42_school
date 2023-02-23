/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:32:34 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/23 15:06:21 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_next(int line, int i)
{
	if (data()->map.map[line][i] != '1')
		return (1);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_close(data);
	if (keysym == XK_Down || keysym == XK_s)
	{
		if (check_next(data->player.line + 1, data->player.i))
			data->player.line++;
	}
	if (keysym == XK_Up || keysym == XK_w)
	{
		if (check_next(data->player.line - 1, data->player.i))
		data->player.line--;
	}
	if (keysym == XK_Left || keysym == XK_a)
	{
		if (check_next(data->player.line, data->player.i - 1))
		data->player.i--;
	}
	if (keysym == XK_Right || keysym == XK_d)
	{
		if (check_next(data->player.line, data->player.i + 1))
		data->player.i++;
	}
	return (0);
}
