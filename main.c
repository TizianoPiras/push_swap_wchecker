/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:27:32 by ertiz             #+#    #+#             */
/*   Updated: 2023/06/02 17:31:47 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**matrix;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (ac == 2)
	{
		matrix = ft_split(av[1], ' ');
		stack_init(&a, matrix, 2);
	}
	if (ac > 2)
		stack_init(&a, av + 1, 0);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, true);
		else if (stack_len(a) == 3)
			sorty(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
