/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:53:36 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/11 15:10:14 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	swap_exec(t_stack **stack, int flag)
{
	t_stack	*curr;
	(void) flag;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	curr = (*stack)->next;
	(*stack)->next = curr->next;
	curr->next = *stack;
	*stack = curr;
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
	}
}
