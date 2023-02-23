/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:59:59 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/23 15:38:40 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	**map_copy(char **map)
{
	char	**map2;
	int		i;
	int		j;

	i = 0;
	map2 = malloc(sizeof (char *) * (data()->map.map_lines + 1));
	while (i < data()->map.map_lines)
	{
		j = -1;
		map2[i] = malloc(sizeof (char) * data()->map.map_elem + 1);
		map2[i][data()->map.map_elem] = 0;
		while (++j < data()->map.map_elem)
			map2[i][j] = map[i][j];
		i++;
	}
	map2[data()->map.map_lines] = 0;
	return (map2);
}
