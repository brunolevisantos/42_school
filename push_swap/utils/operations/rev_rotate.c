/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:22:29 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/06 12:24:32 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	rev_rotate_exec(t_stack **stack, int flag)
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
	if (flag == 1)
		write(1, "rra\n", 4);
	else if (flag == 2)
		write(1, "rrb\n", 4);
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
		if (i == 2)
			write(1, "rrr\n", 4);
	}
}
