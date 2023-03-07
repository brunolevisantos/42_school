/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:01:46 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/07 09:37:32 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	fill_list(t_program **list, int argc, char **argv, char **envp)
{
	int			i;
	t_program	*node;
	t_program	*curr;

	i = 2;
	while (i < argc - 1)
	{
		node = malloc(sizeof(t_program));
		node->i = i;
		node->fd[0] = 0;
		node->fd[1] = 0;
		node->path = check_access(get_path(envp), argv[i]);
		node->flags = ft_split(argv[i], " ");
		node->next = 0;
		if (!list)
			*list = node;
		curr = *list;
		while (curr->next != 0)
			curr = curr->next;
		curr->next = node;
	}
}

node->fd[0] = open(argv[1], O_RDONLY);

int	main(int argc, char **argv, char **envp)
{
	t_program	*list;

	list = 0;
	i = 2;
	if (argc > 2) //maior que 5
	{
		list = fill_list(&list, argc, argv, envp);
		//while list
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
