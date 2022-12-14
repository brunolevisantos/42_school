/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:28:53 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/10 14:59:32 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorted(t_stack **stacka)
{
	t_stack	*curr;

	curr = *stacka;
	while (curr->next)
	{
		if (curr->num < curr->next->num)
			curr = curr->next;
		else
			return (0);
	}
	return (1);
}

void	run_algorithm(t_stack **stacka, t_stack **stackb)
{
	if (sorted(stacka))
		return ;
	if (list_size(stacka) == 2)
		swap(stacka, stackb, 1);
	else if (list_size(stacka) == 3)
		sort_three(stacka, stackb, 1);
	else
		sort_general(stacka, stackb);
}
