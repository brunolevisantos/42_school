/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:51:41 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/02 15:58:29 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../../include/pipex.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void	ft_puthex_fd(unsigned long int n, int fd, char c, int *bytesp);
void	ft_putpointer_fd(unsigned long int n, int fd, int *bytesp);
void	ft_putstr_fd(char *s, int fd, int *bytesp);
void	ft_putnbr_fd(long int n, int fd, int *bytesp);
void	ft_putchar_fd(char c, int fd, int *bytesp);
size_t	ft_strlen_print(const char *s);

#endif
