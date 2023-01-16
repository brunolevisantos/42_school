/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:58:06 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/16 10:01:06 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**str;
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
			str = ft_split(*argv, ' ');
			i = 0;
			while (str && str[i] && !error)
				add_node(&stacka, atoi_two(str[i++], &error), &error, str);
			string_clear(str);
		}
		if (error)
			list_clear(&stacka, &error);
		else
			run_algorithm(&stacka, &stackb);
		list_clear(&stacka, &error);
	}
}
