/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:10:56 by thsion            #+#    #+#             */
/*   Updated: 2023/11/03 15:38:52 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *count)
{
	int	i;

	if (!str)
	{
		ft_putstr("(null)", count);
		return ;
	}
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], count);
		i++;
	}
}

void	ft_putnbr(int nb, int *count)
{
	long int	number;

	number = nb;
	if (number < 0)
	{
		number = number * (-1);
		ft_putchar('-', count);
	}
	if (number >= 10)
		ft_putnbr(number / 10, count);
	ft_putchar(number % 10 + '0', count);
}

void	ft_putpointer(unsigned long arg, int *count)
{
	if (!arg)
		ft_putstr("(nil)", count);
	else
	{
		ft_putstr("0x", count);
		ft_putnbr_base_ul(arg, "0123456789abcdef", count);
	}
}

void	ft_putnbr_base(unsigned int nbr, char *base, int *count)
{
	unsigned int	lengh;

	lengh = 0;
	lengh = ft_strlen(base);
	if (nbr >= lengh)
		ft_putnbr_base(nbr / lengh, base, count);
	ft_putchar(base[nbr % lengh], count);
}

void	ft_putnbr_base_ul(unsigned long nbr, char *base, int *count)
{
	unsigned long	lengh;

	lengh = 0;
	lengh = ft_strlen(base);
	if (nbr >= lengh)
		ft_putnbr_base_ul(nbr / lengh, base, count);
	ft_putchar(base[nbr % lengh], count);
}
