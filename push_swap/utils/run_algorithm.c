/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:28:53 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/08 09:06:26 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//retirar quando pronto
void	print_stack(t_stack **stacka, t_stack **stackb)
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
	/* print_stack(stacka, stackb); */
	if (sorted(stacka))
		return ;
	if (list_size(stacka) == 2 && !sorted(stacka))
		swap(stacka, stackb, 1);
	else if (list_size(stacka) == 3 && !sorted(stacka))
		sort_three(stacka, stackb, 1);
	else
		sort_general(stacka, stackb);
	while (!sorted(stacka))
		rotate(stacka, stackb, 1); //loop infinito
/* 	print_stack(stacka, stackb); */
}
