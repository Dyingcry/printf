/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:34:01 by thsion            #+#    #+#             */
/*   Updated: 2023/11/03 14:39:23 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_strlen(char *str);

void	ft_sign(char sign, va_list pi, int *count);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(int nb, int *count);
void	ft_putpointer(unsigned long arg, int *count);
void	ft_putnbr_base(unsigned int nbr, char *base, int *count);
void	ft_putnbr_base_ul(unsigned long nbr, char *base, int *count);

#endif