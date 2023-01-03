/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:28:53 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/03 14:49:13 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	run_algorithm(t_stack **stacka, t_stack **stackb, int *error)
{
	t_stack	*curr;

	curr = *stacka;
	while (curr)
	{
		printf("Stack a: %d\n", (curr)->num);
		curr = curr->next;
	}
	push(stacka, stackb, 1);
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
	list_clear(stacka, error);
	list_clear(stackb, error);
}
