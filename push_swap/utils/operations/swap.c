/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:53:36 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/22 16:56:49 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	swap_exec(t_stack **stack, int flag)
{
	t_stack	*curr;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	curr = (*stack)->next;
	(*stack)->next = curr->next;
	curr->next = *stack;
	*stack = curr;
	if (flag == 1)
		write(1, "sa\n", 3);
	else if (flag == 2)
		write(1, "sb\n", 3);
	return (1);
}

void	swap(t_stack **stacka, t_stack **stackb, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
		swap_exec(stacka, 1);
	else if (flag == 2)
		swap_exec(stackb, 2);
	else if (flag == 3)
	{
		i += swap_exec(stacka, 0);
		i += swap_exec(stackb, 0);
		if (i == 2)
			write(1, "ss\n", 3);
	}
}
