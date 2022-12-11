/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:47:19 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/11 20:33:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	move_buf(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
	{
		buf[i] = 0;
		i++;
	}
	if (buf[i] == '\n')
	{
		buf[i] = 0;
		i++;
		while (buf[i])
		{
			buf[j] = buf[i];
			buf[i] = 0;
			j++;
			i++;
		}
	}
}
