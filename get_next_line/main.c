/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:24:10 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/09 16:42:51 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;

	fd = open("file_to_read.txt", O_RDONLY);
	printf("%s", get_next_line2(fd));
	printf("%s", get_next_line2(fd));
	printf("%s", get_next_line2(fd));
	printf("%s", get_next_line2(fd));
	printf("%s", get_next_line2(fd));
	printf("%s", get_next_line2(fd));
}
