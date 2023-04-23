/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:03:27 by bde-seic          #+#    #+#             */
/*   Updated: 2023/04/12 05:29:49 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sighandler2(int signum)
{
	(void)signum;
	g_line = readline("");
	while (g_line)
	{
		if (g_line[0] != 0)
		{
			add_history(g_line);
			printf("%s\n", g_line);
		}
		free (g_line);
		g_line = readline("levishell> ");
	}
}
