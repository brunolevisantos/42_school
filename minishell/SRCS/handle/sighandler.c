/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:02:42 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/24 02:23:12 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sighandlerquit(int signum)
{
	if (!meta()->hc)
	{
		if (signum == SIGQUIT && meta()->exec)
		{
			ft_putstr_fd("Quit (core dumped)\n", 2);
			meta()->exitcode = 131;
			return ;
		}
		else if (signum == SIGQUIT && !meta()->exec)
			SIG_IGN ;
	}
}

void	sighandler(int signum)
{
	if (!meta()->hc)
	{
		meta()->exitcode = 130;
		if (signum == SIGINT)
		{
			if (meta()->exec)
			{
				ft_putstr_fd("\n", 2);
				return ;
			}
			ft_putstr_fd("^C\n", 2);
			// rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
		}
	}
}

void	sighandlerhc(int signum)
{
	if (meta()->hc)
	{
		if (signum == SIGINT)
		{
			ft_putstr_fd("^C\n", 2);
			clear_last();
			exit(1);
		}
		if (signum == SIGQUIT)
			SIG_IGN ;
	}
}
