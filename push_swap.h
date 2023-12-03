/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:23:34 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/03 16:39:01 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}t_stack;

// ARGV CHECKERS
int		is_nbr(int argc, char **argv);
void	checker(int argc, char **argv);
int		is_in_limit(int argc, char **argv);
int		is_dupe(char **argv, int argc);
// ---------------------

// LST FUNCS
t_stack	*ft_lstnew(int nbr);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **alst, t_stack *new);
int		ft_lstsize(t_stack *lst);
int		get_min_value(t_stack **a_stack);
// ------------------

// SORT FUNCS
void	sort_list(t_stack **a_stack, t_stack **b_stack);
void	sort_3(t_stack **a_stack, t_stack **b_stack);
void	sort_4(t_stack **a_stack, t_stack **b_stack, int min_value);
void	sort_5(t_stack **a_stack, t_stack **b_stack, int min_value);
// --------------------

// MOVES
void	sa(t_stack **a_stack);
void	sb(t_stack **b_stack);
int		swap(t_stack **stack);
void	ra(t_stack **a_stack);
void	rb(t_stack **b_stack);
void	pb(t_stack **a_stack, t_stack **b_stack);
void	pa(t_stack **a_stack, t_stack **b_stack);
void	rra(t_stack **a_stack);

// ------------------

#endif