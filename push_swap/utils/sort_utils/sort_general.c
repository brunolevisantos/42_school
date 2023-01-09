/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:20:02 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/09 23:12:47 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*best_neighbour(t_stack **stacka, t_stack **stackb)
{
	t_stack	*ca;
	t_stack	*best;
	int		diff;

	diff = INT_MAX;
	ca = *stacka;
	best = 0;
	while (ca)
	{
		if (ca->num > (*stackb)->num && ca->num - (*stackb)->num < diff)
		{
			best = ca;
			diff = ca->num - (*stackb)->num;
		}
		ca = ca->next;
	}
	if (!best)
		best = min_node(stacka);
	return (best);
}

void	sort_general(t_stack **stacka, t_stack **stackb)
{
	below_avg_to_b(stacka, stackb);
	sort_three(stacka, stackb, 1);
	while (*stackb)
	{
		best_to_top(stacka, stackb, max_node(stackb), 2);
		best_to_top(stacka, stackb, best_neighbour(stacka, stackb), 1);
		push(stackb, stacka, 1);
	}
	best_to_top(stacka, stackb, min_node(stacka), 1);
}
