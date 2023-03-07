/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_my_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:24:59 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/07 15:03:32 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_my_list(t_program *list)
{
	t_program	*curr;
	int			i;

	curr = list;
	while (curr)
	{
		list = curr->next;
		free(curr->path);
		i = 0;
		while (curr->flags[i])
			free(curr->flags[i++]);
		free(curr->flags);
		free(curr);
		curr = list;
	}
	free (list);
}
