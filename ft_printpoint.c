/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:41:17 by tpiras            #+#    #+#             */
/*   Updated: 2023/06/02 20:29:33 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	len_pointer(unsigned long long p)
{
	int	i;

	i = 0;
	while (p != 0)
	{
		i++;
		p = p / 16;
	}
	return (i);
}

void	ft_putpointer(unsigned long long p)
{
	if (p >= 16)
	{
		ft_putpointer(p / 16);
		ft_putpointer(p % 16);
	}
	else
	{
		if (p <= 9)
			ft_putchar_fd((p + '0'), 1);
		else
			ft_putchar_fd((p - 10 + 'a'), 1);
	}
}

int	ft_printpoint(unsigned long long ptr)
{
	int	len_print;

	len_print = 0;
	len_print += write(1, "0x", 2);
	if (ptr == 0)
		len_print += write(1, "0", 1);
	else
	{
		ft_putpointer(ptr);
		len_print += len_pointer(ptr);
	}
	return (len_print);
}
