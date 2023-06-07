/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:42:24 by tpiras            #+#    #+#             */
/*   Updated: 2023/06/02 21:58:39 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "checker.h"

void printStack(t_stack* stack) 
{
	int position = 1;
	t_stack* current = stack;
	while (current != NULL) 
	{
		ft_printf("Position: %d, Value: %d\n", position, current->nbr);
		current = current->next;
		position++;
	}
	if (current == NULL)
		ft_printf("(null/void)\n");
}

void	iterate(t_stack **a, t_stack **b, char *str)
{
	while (str)
	{
		if (ft_strncmp(str, "pa", 2) == 0)
			pa(a, b, false);
		else if (ft_strncmp(str, "pb", 2) == 0)
			pb(b, a, false);
		else if (ft_strncmp(str, "sa", 2) == 0)
			sa(a, false);
		else if (ft_strncmp(str, "sb", 2) == 0)
			sb(b, false);
		else if (ft_strncmp(str, "ss", 2) == 0)
			ss(a, b, false);
		else
			check_rotate(a, b, str);
		free(str);
		str = get_next_line(0);
	}
	ft_printf("after operation, stack a is: \n");
	printStack(*a);
	ft_printf("and b is: \n");
	printStack(*b);
	stamp(*a);
}

void	check_rotate(t_stack **a, t_stack **b, char *str)
{
	if (ft_strncmp(str, "ra", 2) == 0)
		ra(a, false);
	else if (ft_strncmp(str, "rb", 2) == 0)
		rb(b, false);
	else if (ft_strncmp(str, "rra", 3) == 0)
		rra(a, false);
	else if (ft_strncmp(str, "rrb", 3) == 0)
		rrb(b, false);
	else if (ft_strncmp(str, "rrr", 3) == 0)
		rrr(a, b, false);
	else if (ft_strncmp(str, "rr", 2) == 0)
		rr(a, b, false);
	else
	{
		write(1, "Error: command not found\n", 25);
		write(1, "Try with:\n pb, pa, sa, sb, ss, ra, rb, rr, rra, rrb, rrr.\n", 58);
		//exit(2);
	}
}

int	checking_stack(t_stack *stack)
{
	int	i;
	
	i = 0;
	while (i < stack_len(stack))
	{
		if (stack->nbr <= stack->next->nbr)
		{
			ft_printf("nbr first: %d, second: %d V\n", stack->nbr, stack->next->nbr);
			return (1);
		}
		else
		{
			ft_printf("nbr first: %d, second: %d X\n", stack->nbr, stack->next->nbr);
			return (0);
		}
		i++;
	}
	return (2);
}

void	stamp(t_stack *stack)
{
	int	i;
	
	t_stack* current = stack;
	i = 1;
	ft_printf("Checking...\n\n");
	while (current && current->next)
	{
		if (checking_stack(current) == 1)
			i++;
		else
			i--;
		current = current->next;
	}
	if (i == stack_len(stack))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

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
	ft_printf("The stack a input is: \n");
	printStack(a);
	iterate(&a, &b, get_next_line(0));
	free_stack(&a);
	return (0);
}
