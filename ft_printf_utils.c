/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:57:31 by tpiras            #+#    #+#             */
/*   Updated: 2023/06/02 20:34:41 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int		i;
	char	*nbr;

	i = 0;
	nbr = ft_itoa(n);
	i = ft_printstr(nbr);
	free(nbr);
	return (i);
}

int	ft_printperc(void)
{
	write (1, "%", 1);
	return (1);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd != -1)
		write(fd, &c, 1);
}
