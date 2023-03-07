/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:01:46 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/07 22:06:38 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_program	*list;
	t_program	*curr;
	int			pid;

	list = 0;
	if (argc >= 5)
	{
		fill_list(&list, argc, argv, envp);
		curr = list;
		while (curr && curr->i <= argc - 2)
		{
			if (pipe(curr->fd) == -1)
				perror ("pipe");
			pid = fork();
			if (pid == -1)
				perror ("fork");
			if (pid == 0)
			{
				set_fd(curr, &list, argc, argv);
				dup2(curr->fd[0], 0);
				close(curr->fd[0]);
				dup2(curr->fd[1], 1);
				close(curr->fd[1]);
				if (execve(curr->path, curr->flags, envp) == -1)
					perror("could not execute\n");
			}
			curr = curr->next;
		}
		while (waitpid(-1, NULL, WNOHANG))
		free_my_list(list);
	}
}
