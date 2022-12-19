/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:12:29 by bde-seic          #+#    #+#             */
/*   Updated: 2022/11/03 15:58:53 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//adiciona no fim da lista um node novo.
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!new || !lst)
		return ;
	current = *lst;
	if (current)
	{	
		while (current -> next)
			current = current -> next;
		current -> next = new;
	}
	else
		*lst = new;
}
