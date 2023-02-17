/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:59:59 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/17 10:00:52 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	**map_copy(char **map)
{
	char	**map2;
	int		i;
	int		j;

	i = 0;
	map2 = malloc(sizeof (char *) * data()->map.map_lines);
	while (i < data()->map.map_lines)
	{
		j = 0;
		map2[i] = malloc(sizeof (char) * data()->map.map_elem);
		while (j < data()->map.map_elem)
			map2[i][j] = map[i][j++];
		i++;
	}
	return (map2);
}
