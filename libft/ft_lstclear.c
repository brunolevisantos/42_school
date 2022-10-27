/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:37:45 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/27 14:51:56 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*aux;

	if (!*lst)
		return ;
	current = *lst;
	while (current != NULL)
	{
		aux = current;
		current = current -> next;
		del((t_list *)(aux));
	}
}
