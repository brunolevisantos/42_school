/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:19:52 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/23 16:41:05 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_img	*decide_img(char i)
{
	// if (i == 'P')
	// 	return (&data()->player.img_down);
	if (i == '1')
		return (&data()->objects.wall);
	if (i == '0' || i == 'P')
		return (&data()->objects.floor);
	if (i == 'C')
		return (&data()->objects.candy);
	if (i == 'E')
		return (data()->objects.exit);
	return (0);
}
