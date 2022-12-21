/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:25:40 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/21 15:27:14 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_exec(t_stack **stack)
{
	
}

void	rev_rotate(t_stack **stacka, t_stack **stackb, int flag)
{
	if (flag == 1)
	{
		rev_rotate_exec(stacka);
		write(1, "rra\n", 4);
	}
	else if (flag == 2)
	{
		rev_rotate_exec(stackb);
		write(1, "rrb\n", 4);
	}
	else if (flag == 3)
	{
		rev_rotate_exec(stacka);
		rev_rotate_exec(stackb);
		write(1, "rrr\n", 3);
	}
}
