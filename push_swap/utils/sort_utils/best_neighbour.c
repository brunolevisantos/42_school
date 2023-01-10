/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_neighbour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:22:27 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/10 11:22:32 by bde-seic         ###   ########.fr       */
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
