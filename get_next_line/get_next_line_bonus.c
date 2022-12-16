/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:33:35 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/16 12:14:24 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buf[1024][BUFFER_SIZE + 1];
	char		*line;

	line = 0;
	if (buf[fd][0])
	{
		line = ft_strjoin(line, buf[fd]);
		move_buf(buf[fd]);
	}
	while (!ft_strchr(line, '\n') && read(fd, buf[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buf[fd]);
		move_buf(buf[fd]);
	}
	return (line);
}
