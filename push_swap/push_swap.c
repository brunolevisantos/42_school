/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:58:06 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/20 11:05:08 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**string;
	t_stack	**stacka;
	int		i;

	i = 1;
	string = 0;
	stacka = 0;
	if (argc > 1)
	{
		string = ft_split(argv, ' ');
		i = 1;
		while (string[i++])
			add_node(stacka, atoi_two(string[i])); //se falhar atoi e ja houver lista, onde faco free?
		run_algorithm(stacka);
	}
	return (0);
}
