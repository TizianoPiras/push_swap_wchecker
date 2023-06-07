/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:20:29 by tpiras            #+#    #+#             */
/*   Updated: 2023/06/02 20:29:40 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	unbr_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_unitoa(unsigned int n)
{
	char	*nbr;
	int		len;

	len = unbr_len(n);
	nbr = (char *)malloc(sizeof(char) * len + 1);
	while (!nbr)
		return (NULL);
	nbr[len] = '\0';
	len--;
	while (n != 0)
	{
		nbr[len] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (nbr);
}

int	ft_printunbr(unsigned int n)
{
	int		len_print;
	char	*nbr;

	len_print = 0;
	if (n == 0)
		len_print += write(1, "0", 1);
	else
	{
		nbr = ft_unitoa(n);
		len_print += ft_printstr(nbr);
		free(nbr);
	}
	return (len_print);
}
