/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:03:08 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/28 13:30:58 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	print_moves(void)
{
	char	*movements;
	char	*message;
	char	*moves;

	if (data()->stop_print == 0)
	{
		message = 0;
		movements = " movements.";
		moves = ft_itoa(data()->moves);
		message = ft_strjoin(moves, movements);
		mlx_string_put(data()->mlx_ptr, \
		data()->win_ptr, 10, 20, WHITE_PIXEL, message);
		free (message);
	}
	else
		return ;
}
