/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:19:56 by tpiras            #+#    #+#             */
/*   Updated: 2023/06/02 20:29:24 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	check_formats(va_list args, const char format)
{
	int	len_print;

	len_print = 0;
	if (format == 'c')
		len_print += ft_printchar(va_arg(args, int));
	if (format == 's')
		len_print += ft_printstr(va_arg(args, char *));
	if (format == 'p')
		len_print += ft_printpoint(va_arg(args, unsigned long long));
	if (format == 'i' || format == 'd')
		len_print += ft_printnbr(va_arg(args, int));
	if (format == 'u')
		len_print += ft_printunbr(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		len_print += ft_printhex(va_arg(args, unsigned int), format);
	if (format == '%')
		len_print += ft_printperc();
	return (len_print);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len_print;

	i = 0;
	len_print = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len_print += check_formats(args, str[i + 1]);
			i++;
		}
		else
			len_print += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (len_print);
}
