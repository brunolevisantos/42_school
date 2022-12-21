/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:22:29 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/21 18:11:58 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_exec(t_stack **stack, int flag)
{
	t_stack	**curr;

	if (*stack == NULL || (*stack) -> next == NULL)
		return (0);
	curr = *stack;
	while ((*curr) -> next -> next != NULL)
		curr = (*curr) -> next;
	*stack = (*curr) -> next;
	(*curr) -> next = NULL;
	if (flag == 1)
		write(1, "ra\n", 3);
	else if (flag == 2)
		write(1, "rb\n", 3);
	else
		return (1);
}

void	rotate(t_stack **stacka, t_stack **stackb, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
		rotate_exec(stacka, 1);
	else if (flag == 2)
		rotate_exec(stackb, 2);
	else if (flag == 3)
	{
		i += rotate_exec(stacka, 0);
		i += rotate_exec(stackb, 0);
		if (i == 2)
			write(1, "rr\n", 3);
	}
}