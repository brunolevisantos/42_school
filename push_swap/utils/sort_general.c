/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:20:02 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/07 23:43:01 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stacks(t_stack **stacka, t_stack **stackb)
{
	t_stack	*curr;

	curr = *stacka;
	while (curr)
	{
		printf("Stack a: %d\n", (curr)->num);
		curr = curr->next;
	}
	curr = *stackb;
	while (curr)
	{
		printf("Stack b: %d\n", (curr)->num);
		curr = curr->next;
	}
}

void	below_avg_to_b(t_stack **stacka, t_stack **stackb)
{
	int		total;
	int		avg;
	int		lap;
	int		fulllap;
	t_stack	*curr;

	total = 0;
	lap = 0;
	fulllap = list_size(stacka);
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
		if (curr->num < avg || lap >= fulllap)
			push(stacka, stackb, 2);
		else
			rotate(stacka, stackb, 1);
		lap++;
	}	
}

void	sort_general(t_stack **stacka, t_stack **stackb)
{
	t_stack	*ca;
	t_stack	*cb;
	int		rot;
	int		i;

	below_avg_to_b(stacka, stackb);
	sort_three(stacka, stackb, 1);
	print_stacks(stacka, stackb);
	rot = 0;
	while (*stackb)
	{
		ca = *stacka;
		cb = *stackb;
		if (cb->num < ca->num || rot == list_size(stacka))
		{
			push(stackb, stacka, 1);
			i = 0;
			while (i++ < rot)
			{
				rev_rotate(stacka, stackb, 1);
			}
			rot = 0;
		}
		else
			rot += rotate(stacka, stackb, 1);
	}
}