/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:37:45 by bde-seic          #+#    #+#             */
/*   Updated: 2022/11/03 16:03:00 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//aplica a funcao del aos nodes, desde o indicado ate ao fim
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (!*lst)
		return ;
	while (*lst != NULL)
	{
		current = (*lst)-> next;
		(*del)((*lst)-> content);
		free(*lst);
		*lst = current;
	}
}
