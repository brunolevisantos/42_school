/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:29:47 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/23 13:53:09 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	compare_components(char **map, int line, int i)
{
	if (map[line][i] == 'P')
		data()->map.p--;
	if (map[line][i] == 'C')
		data()->map.c--;
	if (map[line][i] == 'E')
		data()->map.e--;
}

int	find_path(char	**map, int line, int i)
{
	compare_components(map, line, i);
	map[line][i] = '1';
	if (map[line][i + 1] != '1')
		find_path(map, line, i + 1);
	if (map[line][i - 1] != '1')
		find_path(map, line, i - 1);
	if (map[line - 1][i] != '1')
		find_path(map, line - 1, i);
	if (map[line + 1][i] != '1')
		find_path(map, line + 1, i);
	if (data()->map.p == 0 && data()->map.c == 0 && data()->map.e == 0)
		return (1);
	return (0);
}

t_point	find_start(char **map)
{
	int				i;
	int				line;
	static t_point	start;

	line = 0;
	while (map[line])
	{
		i = -1;
		while (map[line][++i])
		{
			if (map[line][i] == 'P')
			{
				start.line = line;
				start.i = i;
				start.value = 'P';
				data()->player.i = i;
				data()->player.line = line;
				return (start);
			}	
		}
		line++;
	}
	return (start);
}

int	check_path(char	**map)
{
	t_point	start;
	char	**map2;

	map2 = map_copy(map);
	start = find_start(map);
	if (find_path(map2, start.line, start.i) && map_free(map2))
		return (1);
	else
	{
		map_free(map2);
		handle_msg("Invalid path!");
		return (0);
	}
}
