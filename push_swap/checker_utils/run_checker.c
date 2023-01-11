/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:09:58 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/11 15:12:37 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	sorted(t_stack **stacka)
{
	t_stack	*curr;

	curr = *stacka;
	while (curr->next)
	{
		if (curr->num < curr->next->num)
			curr = curr->next;
		else
			return (0);
	}
	return (1);
}

void	check_sorted(t_stack **stacka, t_stack **stackb)
{
	if (sorted(stacka) && !stackb)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	run_checker(t_stack **stacka, t_stack **stackb)
{
	char	*line;
	
	line = 0;
	while (?);
	{
		line = get_next_line(1);
		if (my_strcmp(line, "rra"))
			checker_rev_rotate(stacka, stackb, 1);
		if (my_strcmp(line, "rrb"))
			checker_rev_rotate(stacka, stackb, 2);
		if (my_strcmp(line, "ra"))
			checker_rotate(stacka, stackb, 1);
		if (my_strcmp(line, "rb"))
			checker_rotate(stacka, stackb, 2);
		if (my_strcmp(line, "sa"))
			checker_swap(stacka, stackb, 1);
		if (my_strcmp(line, "pa"))
			checker_push(stackb, stacka, 1);
		if (my_strcmp(line, "pb"))
			checker_push(stacka, stackb, 2);
	}
	check_sorted(stacka);
}