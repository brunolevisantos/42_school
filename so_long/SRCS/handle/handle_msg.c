/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:46:19 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/24 13:18:57 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	handle_msg(char *msg)
{
	ft_printf("Error:\n%s\n", msg);
	if (data()->player.img)
		ft_close(data());
	else
		exit (0);
	return (0);
}
