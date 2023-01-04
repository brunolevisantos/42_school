/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:28:53 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/04 16:24:55 by bde-seic         ###   ########.fr       */
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

void	sort_three(t_stack **stacka, t_stack **stackb)
{
	t_stack	*curr;

	curr = *stacka;
	if (curr->num > curr->next->num && curr->next->next->num > curr->num)
		swap(stacka, stackb, 1);
}

void	run_algorithm(t_stack **stacka, t_stack **stackb)
{
	print_stack(stacka, stackb);
/* 	if (sorted(stacka) + size = 1 + size = 2?);
		break ; */
	sort_three(stacka, stackb);
	print_stack(stacka, stackb);
}
