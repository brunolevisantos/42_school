/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:01:46 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/07 10:36:46 by bde-seic         ###   ########.fr       */
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

void	set_fd(t_program *curr, int argc, char **argv)
{
	if (curr->i == 2)
		curr->fd[0] = open(argv[1], O_RDONLY);
	else
		curr->fd[0] = get_previous_fd();
	if (curr-> i == argc - 2)
		curr->fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		curr->fd[1] = ;
}

int	main(int argc, char **argv, char **envp)
{
	t_program	*list;
	t_program	*curr;
	int			pid;

	list = 0;
	if (argc > 5)
	{
		fill_list(&list, argc, argv, envp);
		curr = list;
		while (curr->i < argc - 1)
		{
			if (pipe(curr->fd) == -1)
				perror ("pipe");
			set_fd(&curr, argc, argv);
			pid = fork();
			if (pid == -1)
				perror ("fork");
			if (pid == 0)
			{
				dup2(curr->fd[1], 1);
				if (execve(curr->path, curr->flags, envp) == -1)
					perror("could not execute\n");
				// free(path);
			}
			curr = curr-> next;
		}
		waitpid();
		free //all
	}
}
