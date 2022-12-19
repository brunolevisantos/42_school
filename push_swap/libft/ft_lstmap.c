/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:20:04 by bde-seic          #+#    #+#             */
/*   Updated: 2022/11/03 16:36:07 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//cria uma nova lista com o resultado da funcao f aplicado a lista inicial
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*nlcurrent;

	if (lst)
	{
		newlist = ft_lstnew((*f)(lst -> content));
		lst = lst -> next;
		while (lst)
		{
			nlcurrent = ft_lstnew((*f)(lst -> content));
			if (!nlcurrent -> content)
			{
				(*del)(nlcurrent -> content);
				free(nlcurrent);
			}
			ft_lstadd_back(&newlist, nlcurrent);
			lst = lst -> next;
		}
		return (newlist);
	}
	return (0);
}
