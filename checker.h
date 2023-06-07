/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:47:17 by tpiras            #+#    #+#             */
/*   Updated: 2023/06/02 20:35:07 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./push_swap.h"
# include "get_next_line/get_next_line.h"

void	iterate(t_stack **a, t_stack **b, char *str);
int		checking_stack(t_stack *stack);
int		main(int argc, char **argv);
void	check_rotate(t_stack **a, t_stack **b, char *str);
void	stamp(t_stack *stack);

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
void	ft_putchar_fd(char c, int fd);
char    *itoa(int n);

#endif