/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:13:11 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/23 15:38:28 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_map_name(char *map_path)
{
	int	fd;
	int	i;

	i = -1;
	fd = 0;
	while (map_path[++i])
		;
	if (map_path[i - 1] == 'r' && map_path[i - 2] == 'e' \
		&& map_path[i - 3] == 'b' && map_path[i - 4] == '.')
		fd = open(map_path, O_RDONLY);
	return (fd);
}
