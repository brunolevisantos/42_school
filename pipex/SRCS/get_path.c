/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:12:02 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/09 10:51:24 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**get_path(char **envp)
{
	int		i;
	char	*env_var;
	char	**paths;

	i = 0;
	env_var = envp[i];
	paths = 0;
	while (!ft_strnstr(env_var, "PATH=", 5))
		env_var = envp[i++];
	if (!env_var)
	{
		perror ("PATH not found");
		exit (0);
	}
	env_var = trim_path(env_var);
	paths = ft_split(env_var, ':');
	free (env_var);
	return (paths);
}
