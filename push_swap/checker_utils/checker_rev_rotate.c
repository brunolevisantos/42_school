/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rev_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:22:29 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/12 11:33:58 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	cheker_rev_rotate_exec(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*new_first;
	t_stack	*old_first;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	curr = *stack;
	old_first = *stack;
	while (curr->next->next != NULL)
		curr = curr->next;
	new_first = curr->next;
	curr->next = NULL;
	new_first->next = old_first;
	*stack = new_first;
	return (1);
}

void	checker_rev_rotate(t_stack **stacka, t_stack **stackb, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
		cheker_rev_rotate_exec(stacka);
	else if (flag == 2)
		cheker_rev_rotate_exec(stackb);
	else if (flag == 3)
	{
		i += cheker_rev_rotate_exec(stacka);
		i += cheker_rev_rotate_exec(stackb);
	}
}
