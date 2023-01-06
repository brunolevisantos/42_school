/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:20:02 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/06 20:51:21 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	below_avg_to_b(t_stack **stacka, t_stack **stackb)
{
	int		total;
	int		avg;
	t_stack	*curr;

	total = 0;
	curr = *stacka;
	while (curr)
	{
		total += curr->num;
		curr = curr->next;
	}
	avg = total / (list_size(stacka));
	curr = *stacka;
	while(list_size(stacka) > 3)
	{
		if (curr->num < avg)
			push(stacka, stackb, 2);
		else
			rotate(stacka, stackb, 1);
	}	
}

void	sort_general(t_stack **stacka, t_stack **stackb)
{
	t_stack	*ca;
	t_stack	*cb;

	ca = *stacka;
	cb = *stackb;
	below_avg_to_b(stacka, stackb);
	sort_three(stacka, stackb, 1);
	while (list_size(stackb))
	{
		if (cb->num < ca->num)
			push(stackb, stacka, 1);
		else
	}
}