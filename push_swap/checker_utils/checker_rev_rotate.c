/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rev_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:22:29 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/11 15:11:17 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	rev_rotate_exec(t_stack **stack, int flag)
{
	t_stack	*curr;
	t_stack	*new_first;
	t_stack	*old_first;
	(void) flag;

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

void	rev_rotate(t_stack **stacka, t_stack **stackb, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
		rev_rotate_exec(stacka, 1);
	else if (flag == 2)
		rev_rotate_exec(stackb, 2);
	else if (flag == 3)
	{
		i += rev_rotate_exec(stacka, 0);
		i += rev_rotate_exec(stackb, 0);
	}
}
