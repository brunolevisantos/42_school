/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:20:04 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/30 16:45:53 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
