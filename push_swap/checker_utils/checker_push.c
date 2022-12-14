/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:05:50 by bde-seic          #+#    #+#             */
/*   Updated: 2023/01/12 10:47:50 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	checker_push(t_stack **stackfrom, t_stack **stackto)
{
	t_stack	*move;

	move = *stackfrom;
	*stackfrom = (*stackfrom)->next;
	if (*stackto)
		move->next = *stackto;
	else
		move->next = NULL;
	*stackto = move;
}
