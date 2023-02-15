/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:24:05 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/15 15:48:26 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_core(char **map)
{
	
}

int	check_walls(char **map) // confirmar que o line nao chega a null
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (map[0][i])
		if (map[0][i++] != 1)
			handle_msg("Not wall covered\n");
	i = 0;
	while (map[data()->map_lines][i])
		if (map[data()->map_lines][i++] != 1)
			handle_msg("Not wall covered\n");
	i = 0;
	while (line)
		if (map[line][0] && map[line++][data()->map_elem] != 1)
			handle_msg("Not wall covered\n");
	return (1);
}

int	check_rect(char **map)
{
	int	line;

	line = 0;
	while (line < data()->map_lines)
	{
		if (elem_count(map[line++]) != data()->map_elem)
			handle_msg("Not a rectangle\n");
	}
	return (1);
}

int	map_checker(void)
{
	int		fd;

	fd = open("map.ber", O_RDONLY);
	(data())->map = load_map_zico(0, fd, 0);
	data()->map_lines = line_count(data()->map);
	data()->map_elem = elem_count(data()->map[0]);
	if (check_rect(data()->map) && check_walls(data()->map) && \
		check_core(data()->map));
			return (1);
	close(fd);
	return (0);
}
