/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:41:17 by tpiras            #+#    #+#             */
/*   Updated: 2023/06/02 20:29:29 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	len_hex(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

void	ft_puthex(unsigned int nbr, const char format)
{
	if (nbr >= 16)
	{
		ft_puthex(nbr / 16, format);
		ft_puthex(nbr % 16, format);
	}
	else
	{
		if (nbr <= 9)
			ft_printchar(nbr + '0');
		else
		{
			if (format == 'x')
				ft_printchar(nbr - 10 + 'a');
			if (format == 'X')
				ft_printchar(nbr - 10 + 'A');
		}
	}
}

int	ft_printhex(unsigned int nbr, const char format)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(nbr, format);
	return (len_hex(nbr));
}
