/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:02:46 by ertiz             #+#    #+#             */
/*   Updated: 2023/06/02 20:32:51 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	int				act_index;
	int				value;
	bool			ab_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//stack initialization functions (stack_init.c)

t_stack	*find_last_node(t_stack *head);
void	append_node(t_stack **stack, int nbr);
void	stack_init(t_stack **a, char **av, int flag_ac2);

//push moves functions (push.c)

void	pa(t_stack **a, t_stack **b, bool check);
void	pb(t_stack **a, t_stack **b, bool check);

//swap moves functions (swap.c)

void	sa(t_stack **a, bool check);
void	sb(t_stack **b, bool check);
void	ss(t_stack **a, t_stack **b, bool check);

//rotate moves functions (rotate.c)

void	ra(t_stack **a, bool check);
void	rb(t_stack **b, bool check);
void	rr(t_stack **a, t_stack **b, bool check);

//reverse rotate moves functions (reverse_rotate.c)

void	rra(t_stack **a, bool check);
void	rrb(t_stack **b, bool check);
void	rrr(t_stack **a, t_stack **b, bool check);

//initialization functions (init.c)

void	set_current_position(t_stack *stack);
void	init_nodes(t_stack *a, t_stack *b);

//sorting and cheacking functions (push_swap_utils.c & short_sort.c)

int		stack_len(t_stack *stack);
void	node_evaluation(t_stack *a, t_stack *b);
void	sorty(t_stack **a);
void	handle_five(t_stack **a, t_stack **b);
void	set_cheapest(t_stack *b);
bool	is_sorted(t_stack *stack);
t_stack	*return_cheapest(t_stack *stack);
t_stack	*is_smallest(t_stack *stack);

//push_swap algoritm (push_swap.c)

void	finish_rotation(t_stack **stack, t_stack *top, char stack_name);
void	push_swap(t_stack **a, t_stack **b);

//errors menagement (errors.c)

int		error_repetation(t_stack *a, int nbr);
int		error_syntax(char *str_nbr);
void	error_free(t_stack **a, char **av, bool flag_ac2);
void	free_stack(t_stack **stack);
void	free_matrix(char **av);

//printf functions

int		ft_printchar(char c);
int		check_formats(va_list args, const char format);
int		ft_printf(const char *str, ...);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_printperc(void);
int		ft_printpoint(unsigned long long ptr);
int		ft_printunbr(unsigned int n);
int		unbr_len(unsigned int n);
int		len_hex(unsigned int n);
int		len_pointer(unsigned long long p);
int		ft_printhex(unsigned int n, const char format);
void	ft_putstr(char *str);
void	ft_putpointer(unsigned long long p);
void	ft_puthex(unsigned int nbr, const char format);
char	*ft_unitoa(unsigned int n);
char    *itoa(int n);

#endif