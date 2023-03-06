/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:01:46 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/06 00:10:29 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv)
{
	// ver uso de char *envp[]
	int	fd[2];
	int	pid;
	int	i;
	char	cmd[] = "/usr/bin/wc"; //corrigir para nome do progarma certo
	char	*argVec[] = {"wc", "-l", argv[1], NULL};
	char	*envVec[] = {NULL};
	
	i = -1;
	if (argc > 2) //corrigir p maior que 5
	{
		if (pipe(fd) == -1)
			perror ("pipe");
		pid = fork();
		if (pid == -1)
			perror ("fork");
		else if (pid == 0)
		{
			fd[0] = open(argv[1], O_RDONLY);
			while (argv[++i])
			fd[1] = open(argv[i - 1], O_WRONLY | O_CREAT, 0777); //ver como apagar o que la esta
			dup2(fd[1], 1);
			printf("Start of execve call %s\n", cmd);
			if (execve(cmd, argVec, envVec) == -1)
				perror("could not execute\n");
		}
		else if (pid != 0) //esta sempre a fazer o parent process 
			printf("Something went wrong\n"); 
	}
}
