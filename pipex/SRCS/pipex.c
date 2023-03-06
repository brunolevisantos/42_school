/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:01:46 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/06 15:39:56 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pid;
	int		i;
	char	*path;
	char	*argVec[] = {"ls", "-l", argv[1], NULL};

	i = 2;
	if (argc > 2) //maior que 5
	{
		if (pipe(fd) == -1)
			perror ("pipe");
		pid = fork();
		if (pid == -1)
			perror ("fork");
		else if (pid == 0)
		{
			path = check_access(get_path(envp), argv[i]);
			fd[0] = open(argv[1], O_RDONLY);
			fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			dup2(fd[1], 1);
			if (execve(path, argVec, envp) == -1)
				perror("could not execute\n");
			// free(path);
			}
/* 		else if (pid != 0) //esta sempre a fazer o parent process 
			printf("Something went wrong\n");  */
	}
}
