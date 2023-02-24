/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:32:37 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/24 16:25:54 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{	
		if (map_checker(av[1]))
		{
			initialize();
			fill_obj(data());
			mlx_loop_hook(data()->mlx_ptr, render, data());
			mlx_hook(data()->win_ptr, KeyPress, KeyPressMask, \
			handle_keypress, data());
			mlx_hook(data()->win_ptr, 17, 0, ft_close, data());
			mlx_loop(data()->mlx_ptr);
		}
	}
	else
		handle_msg("Invalid number of arguments.");
}
