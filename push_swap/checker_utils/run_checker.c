/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:09:58 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/12 13:24:32 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	print_stack(t_stack **stack)
{
	t_stack	*curr;

	curr = *stack;
	while (curr)
	{
		printf("stacka: %d\n", curr->num);
		curr = curr->next;
	}
}

int	cheker_sorted(t_stack **stacka)
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
	if (cheker_sorted(stacka) && !(*stackb))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	run_checker(t_stack **stacka, t_stack **stackb)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (my_strcmp(line, "rra\n"))
			checker_rev_rotate(stacka, stackb, 1);
		else if (my_strcmp(line, "rrb\n"))
			checker_rev_rotate(stacka, stackb, 2);
		else if (my_strcmp(line, "ra\n"))
			checker_rotate(stacka, stackb, 1);
		else if (my_strcmp(line, "rb\n"))
			checker_rotate(stacka, stackb, 2);
		else if (my_strcmp(line, "sa\n"))
			checker_swap(stacka, stackb, 1);
		else if (my_strcmp(line, "pa\n"))
			checker_push(stackb, stacka);
		else if (my_strcmp(line, "pb\n"))
			checker_push(stacka, stackb);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	check_sorted(stacka, stackb);
}
