/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:33:36 by thsion            #+#    #+#             */
/*   Updated: 2023/11/03 15:41:44 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	pi;
	int		i;
	int		count;

	va_start(pi, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_sign(format[i], pi, &count);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	va_end(pi);
	return (count);
}

void	ft_sign(char sign, va_list pi, int *count)
{
	if (sign == 'c')
		ft_putchar(va_arg(pi, int), count);
	else if (sign == 's')
		ft_putstr(va_arg(pi, char *), count);
	else if (sign == 'p')
		ft_putpointer(va_arg(pi, unsigned long), count);
	else if (sign == 'd' || sign == 'i')
		ft_putnbr(va_arg(pi, int), count);
	else if (sign == 'u')
		ft_putnbr_base(va_arg(pi, unsigned int), "0123456789", count);
	else if (sign == 'x')
		ft_putnbr_base(va_arg(pi, unsigned int), "0123456789abcdef", count);
	else if (sign == 'X')
		ft_putnbr_base(va_arg(pi, unsigned int), "0123456789ABCDEF", count);
	else if (sign == '%')
		ft_putchar(sign, count);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c, int *count)
{
	*count += write(1, &c, 1);
}
/*int    main(void)
{
    ft_printf("ma fonction : %c\n", '0');
    printf("la vraie : %c\n", '0');
    ft_printf("ma fonction : %s\n", "bonjour");
    printf("la vraie: %s\n", "bonjour");
    ft_printf("ma fonction : %d\n", 123456);
    printf("la vraie : %d\n", 123456);
    ft_printf("ma fonction : %i\n", 123456);
    printf("la vraie : %i\n", 123456);
    ft_printf("ma fonction : %u\n", -123456);
    printf("la vraie : %u\n", -123456);
    ft_printf("ma fonction : %x\n", 123456);
    printf("la vraie : %x\n", 123456);
    ft_printf("ma fonction : %X\n", 123456);
    printf("la vraie : %X\n", 123456);
    ft_printf("ma fonction : %%\n");
    printf("la vraie : %%\n");
    ft_printf("ma fonction : %p\n", "bonjour");
    printf("la vraie : %p\n", "bonjour");
    return (0);
}*/
