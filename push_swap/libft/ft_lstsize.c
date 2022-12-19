/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:16:17 by bde-seic          #+#    #+#             */
/*   Updated: 2022/11/03 16:37:37 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//retorna o size da lista
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*count;

	i = 0;
	count = lst;
	while (count)
	{
		count = count -> next;
		i++;
	}
	return (i);
}
