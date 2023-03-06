/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:51:24 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/06 13:56:56 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*join_path(char *path, char *arg)
{
	char	*complete;
	char	*temp;

	temp = ft_strjoin(path, "/");
	complete = ft_strjoin(temp, arg);
	free(temp);
	return (complete);
}
