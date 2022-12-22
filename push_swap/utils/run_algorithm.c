/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:28:53 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/22 16:57:14 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	run_algorithm(t_stack **stacka, t_stack **stackb)
{
	t_stack	*curr;

	curr = *stacka;
	while (curr)
	{
		printf("Stack a: %d\n", (curr)->num);
		curr = curr->next;
	}
	rotate(stacka, stackb, 1);
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
	list_clear(stacka); //corrigir quando manda error. porque tem que limpar tudo antes de sair do programa.
}
