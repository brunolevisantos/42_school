/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   below_avg_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:05:29 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/09 23:09:45 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	avg(t_stack **stack)
{
	int		total;
	t_stack	*curr;

	curr = *stack;
	total = 0;
	while (curr)
	{
		total += curr->num;
		curr = curr->next;
	}
	return (total / (list_size(stack)));
}

void	below_avg_to_b(t_stack **stacka, t_stack **stackb)
{
	t_stack	*curr;

	curr = *stacka;
	while (list_size(stacka) > 3)
	{
		curr = *stacka;
		if (curr->num < avg(stacka))
		{
			push(stacka, stackb, 2);
			if ((*stackb)->num < avg(stackb))
				rotate(0, stackb, 2);
		}
		else
			rotate(stacka, stackb, 1);
	}	
}