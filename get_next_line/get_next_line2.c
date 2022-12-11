/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:52:43 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/09 16:43:47 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char    *line_cut(char *tmpline)
{
    int     i;
    char    *line;

    i = 0;
    line = (char *)malloc(sizeof(char) * ft_strlen(tmpline) + 1);
    while (tmpline[i] != '\0' && tmpline[i] != '\n')
    {
        line[i] = tmpline[i];
        i++;
    }
    line[i] = tmpline[i];
    if (line[i] != '\0')
        line[++i] = '\0';
    return (line);
}

char	*get_next_line2(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*line;

	line = 0;
	while (!ft_strchr(line, '\n'))
	{
        read(fd, buf, BUFFER_SIZE);
        line = ft_strjoin(line, buf);
	}
    line = line_cut(line);
	move_buf(buf);
	return (line);
}
