/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:29:47 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/16 15:48:51 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	find_path(char	**map, int i, int line)
{
	if (map[i + 1][line] != '1')
		find_path(map, i + 1, line);
	if (map[i][line - 1] != '1')
		find_path(map, i, line - 1);
	if (map[i - 1][line] != '1')
		find_path(map, i + 1, line);
	if (map[i][line + 1] != '1')
		find_path(map, i, line + 1);
	if (next.value == 'E')
		return (1);
	else
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
				start.y = line;
				start.x = i;
				start.value = 'P';
			}	
		}
		line++;
	}
	return (start);
}

int	check_path(char	**map)
{
	t_point	start;

	start = find_start(map);
	if (find_path(map, start.x, start.y))
		return (1);
	else
		return (0);
}
