/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:05:47 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/12 13:17:01 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	char	**string;
	t_stack	*stacka;
	t_stack	*stackb;
	int		i;
	int		error;

	stacka = 0;
	stackb = 0;
	error = 0;
	if (argc > 1)
	{
		while (++argv && *argv && !error)
		{
			string = ft_split(*argv, ' ');
			i = 0;
			while (string && string[i] && !error)
				add_node(&stacka, atoi_two(string[i++], &error), &error);
			string_clear(string);
		}
		if (error)
			list_clear(&stacka, &error);
		else
			run_checker(&stacka, &stackb);
		list_clear(&stacka, &error);
	}
}
