/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_zico.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:16:27 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/16 11:44:40 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**load_map_zico(char **map, int fd, int line_count)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		map = load_map_zico(map, fd, line_count + 1);
	else
		map = malloc(sizeof (char *) * (line_count + 1));
	if (map)
		map[line_count] = line;
	return (map);
}
