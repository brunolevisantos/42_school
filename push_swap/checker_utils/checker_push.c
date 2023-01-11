/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:05:50 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/11 15:11:42 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push(t_stack **stackfrom, t_stack **stackto, int flag)
{
	t_stack	*move;
	(void) flag;

	move = *stackfrom;
	*stackfrom = (*stackfrom)->next;
	if (*stackto)
		move->next = *stackto;
	else
		move->next = NULL;
	*stackto = move;
}
