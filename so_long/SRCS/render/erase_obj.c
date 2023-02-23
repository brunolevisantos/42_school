/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:24:26 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/23 15:28:34 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	erase_obj(t_data *data, int i, int line)
{
	if (data->map.map[line][i] == 'C')
		data->map.map[line][i] = '0';
}
