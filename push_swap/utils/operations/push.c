/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:05:50 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/22 15:26:48 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push(t_stack **stackfrom, t_stack **stackto, char flag)
{
	t_stack	*move;

	move = *stackfrom;
	*stackfrom = (*stackfrom)->next;
	if (*stackto)
		move->next = *stackto;
	else
		move->next = NULL;
	*stackto = move;
	if (flag == 'a')
		write(1, "pa\n", 3);
	else if (flag == 'b')
		write(1, "pb\n", 3);
}
