/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   least_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:22:45 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/10 14:28:05 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	bn_cost(t_stack **stacka, t_stack **curr)
{
	int		bn_cost;
	t_stack	*bn;

	bn = best_neighbour(stacka, curr);
	bn_cost = 0;
	if (list_size(&bn) < list_size(stacka) / 2)
		bn_cost = list_size(&bn);
	else
		bn_cost = list_size(stacka) - list_size(&bn);
	return (bn_cost);
}

t_stack	*least_cost(t_stack **stacka, t_stack **stackb)
{
	int		cost;
	int		least_cost;
	int		i;
	t_stack	*curr;
	t_stack	*least;

	cost = 0;
	least_cost = INT_MAX;
	i = 0;
	curr = *stackb;
	while (curr && ++i)
	{
		cost = (i > list_size(stackb) / 2) * list_size(&curr) + \
		(i <= list_size(stackb) / 2) * (list_size(stackb) - list_size(&curr));
		cost += bn_cost(stacka, &curr);
		if (cost < least_cost)
		{
			least_cost = cost;
			least = curr;
		}
		curr = curr->next;
	}
	return (least);
}
