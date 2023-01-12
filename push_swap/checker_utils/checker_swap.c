/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:53:36 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/12 12:09:31 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	cheker_swap_exec(t_stack **stack)
{
	t_stack	*curr;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	curr = (*stack)->next;
	(*stack)->next = curr->next;
	curr->next = *stack;
	*stack = curr;
	return (1);
}

void	checker_swap(t_stack **stacka, t_stack **stackb, int flag)
{
	if (flag == 1)
		cheker_swap_exec(stacka);
	else if (flag == 2)
		cheker_swap_exec(stackb);
	else if (flag == 3)
	{
		cheker_swap_exec(stacka);
		cheker_swap_exec(stackb);
	}
}
