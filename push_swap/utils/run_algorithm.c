/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:28:53 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/04 15:30:33 by bde-seic         ###   ########.fr       */
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

void	run_algorithm(t_stack **stacka, t_stack **stackb, int *error)
{
	print_stack(stacka, stackb); //retirar quando pronto
	swap(stacka, stackb, 1);
	rotate(stacka, stackb, 1);
	print_stack(stacka, stackb); //retirar quando pronto
	list_clear(stacka, error);
	list_clear(stackb, error);
}
