/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:58:06 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/22 21:27:40 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			run_algorithm(&stacka, &stackb, &error);
	}
	return (0);
}
