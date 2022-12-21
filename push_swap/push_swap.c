/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:58:06 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/21 15:01:14 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**string;
	t_stack	**stacka;
	t_stack	**stackb;
	int		i;

	i = 1;
	stacka = 0;
	stackb = 0;
	if (argc > 1)
	{
		string = ft_split(argv, ' ');
		while (string[i])
			add_node(stacka, atoi_two(string[i++], stacka));
		run_algorithm(stacka, stackb);
	}
	return (0);
}
