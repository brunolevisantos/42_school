/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:46:19 by bde-seic          #+#    #+#             */
/*   Updated: 2023/02/16 14:15:58 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	handle_msg(char *msg)
{
	printf("Error:\n%s", msg); //alterar para ft_printf
	if (data()->player.img_player.img)
		ft_close(data());
	else
		exit (0);
	return (0);
}
