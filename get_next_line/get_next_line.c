/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:33:35 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/15 13:59:50 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

	line = 0;
	buf[BUFFER_SIZE] = 0;
	if (fd < 0)
		return (NULL);
	if (buf[0])
		line = ft_strjoin(line, buf);
	while (!ft_strchr(line, '\n') && read(fd, buf, BUFFER_SIZE) > 0)
		line = ft_strjoin(line, buf);
	move_buf(buf);
	return (line);
}
