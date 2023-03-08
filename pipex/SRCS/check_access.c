/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:37:32 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/08 10:18:35 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*check_access(char **paths, char *arg)
{
	int		i;
	char	*temp;

	i = 0;
	temp = join_path(paths[i], arg);
	while (paths[i] && access(temp, F_OK))
	{
		free(temp);
		i++;
		temp = join_path(paths[i], arg);
	}
	// printf("arg = %s\n", arg);
	if (access(temp, F_OK))
	{
		perror ("Program not found");
		exit (0);
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	// printf("cheguei aqui e temp = %s\n", temp);
	free (paths);
	return (temp);
}
