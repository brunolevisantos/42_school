/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:54:53 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/07 15:33:48 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	get_previous_fd(t_program *curr, t_program **list)
{
	int			fd;
	t_program	*iterate;

	iterate = *list;
	while (iterate->i != curr->i - 1)
		iterate = iterate->next;
	fd = iterate->fd[1];
	return (fd);
}

void	set_fd(t_program *curr, t_program **list, int argc, char **argv)
{
	if (curr->i == 2)
		curr->fd[0] = open(argv[1], O_RDONLY);
	else
		curr->fd[0] = get_previous_fd(curr, list);
	if (curr-> i == argc - 2)
		curr->fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
}
