/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:24:05 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/23 13:43:33 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_components(char **map)
{
	int	i;
	int	line;

	line = 0;
	while (map[line])
	{
		i = 0;
		while (map[line][i] && map[line][i] != '\n')
		{
			if (map[line][i] == 'C')
				data()->map.c++;
			else if (map[line][i] == 'E')
				data()->map.e++;
			else if (map[line][i] == 'P')
				data()->map.p++;
			else if (map[line][i] != '1' && map[line][i] != '0')
				handle_msg("Wrong elements!");
			i++;
		}
		line++;
	}
	if (data()->map.c >= 1 && data()->map.e == 1 && data()->map.p == 1)
		return (1);
	else
		return (handle_msg("Wrong elements!"));
}

int	check_walls(char **map)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (map[line][i] != '\n' && map[line][i] != 0)
		if (map[line][i++] != '1')
			handle_msg("Not wall covered!");
	i = 0;
	while (line < (data()->map.map_lines))
		if (map[line][0] != '1' || map[line++][data()->map.map_elem - 1] != '1')
			handle_msg("Not wall covered!");
	i = 0;
	while (map[data()->map.map_lines - 1][i] != '\0')
		if (map[data()->map.map_lines - 1][i++] != '1')
			handle_msg("Not wall covered!");
	return (1);
}

int	check_rect(char **map)
{
	int	line;

	line = 0;
	while (map[line])
	{
		if (elem_count(map[line++]) != data()->map.map_elem)
			handle_msg("Not a rectangle!");
	}
	return (1);
}

int	map_checker(char *map_path)
{
	int		fd;

	fd = check_map_name(map_path);
	if (fd >= 3)
	{
		(data())->map.map = load_map_zico(0, fd, 0);
		close(fd);
		data()->map.map_lines = line_count(data()->map.map);
		data()->map.map_elem = elem_count(data()->map.map[0]);
		if (check_rect(data()->map.map) && check_walls(data()->map.map) && \
			check_components(data()->map.map) && check_path(data()->map.map))
			return (1);
	}
	else
		handle_msg("Map not found!");
	return (0);
}
