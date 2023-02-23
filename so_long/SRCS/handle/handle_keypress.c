/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:32:34 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/23 14:02:08 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	c

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_close(data);
	if (keysym == XK_Down || keysym == XK_s)
	{
		if (check_next(line, i))
			data->player.line++;
	}
	if (keysym == XK_Up || keysym == XK_w)
		data->player.line--;
	if (keysym == XK_Left || keysym == XK_a)
		data->player.i--;
	if (keysym == XK_Right || keysym == XK_d)
		data->player.i++;
	return (0);
}
