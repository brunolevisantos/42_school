/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:25:40 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/12 11:35:22 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	cheker_rotate_exec(t_stack **stack)
{
	t_stack	*save;
	t_stack	*curr;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	save = *stack;
	*stack = (*stack)->next;
	curr = *stack;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = save;
	save->next = NULL;
	return (1);
}

int	checker_rotate(t_stack **stacka, t_stack **stackb, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
		i += cheker_rotate_exec(stacka);
	else if (flag == 2)
		i += cheker_rotate_exec(stackb);
	else if (flag == 3)
	{
		i += cheker_rotate_exec(stacka);
		i += cheker_rotate_exec(stackb);
	}
	return (i);
}
