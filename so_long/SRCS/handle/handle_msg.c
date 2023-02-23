/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:46:19 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/23 17:06:50 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	handle_msg(char *msg)
{
	printf("Error:\n%s\n", msg); //alterar para ft_printf
	if (data()->player.img->img)
		ft_close(data());
	else
		exit (0);
	return (0);
}
