/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:23:34 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/14 14:55:26 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "./ft_printf/ft_printf.h"
# include "stdbool.h"
# include "limits.h"

typedef struct s_stack_node
{
	int					nbr;
	int					idx;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;		
}t_stack_node;

// ARGV CHECKERS
int	is_nbr(int argc, char **argv, int i);
char	**checker(int argc, char **argv);
int	is_in_limit(int argc, char **argv, int i);
int	is_dupe(char **argv, int argc, int i);
int	ft_count(char **split);
int	is_sorted(t_stack_node **a_stack);
// ---------------------

// LST FUNCS
t_stack_node	*ft_lstnew(int nbr);
t_stack_node	*ft_lstlast(t_stack_node *lst);
void			ft_lstadd_back(t_stack_node **alst, t_stack_node *new);
int				ft_lstsize(t_stack_node *lst);
int				get_min_value(t_stack_node **a_stack);
t_stack_node	*ft_lstmax(t_stack_node *lst);
t_stack_node	*ft_lstmin(t_stack_node *lst);
// // ------------------

// SORT FUNCS
void	sort_list(t_stack_node **a_stack, t_stack_node **b_stack);
void	sort_3(t_stack_node **a_stack);
void	a_init_nodes(t_stack_node *a_stack, t_stack_node *b_stack);
void	current_idx(t_stack_node *stack);
void	rotate_them(t_stack_node **a_stack, t_stack_node **b_stack, t_stack_node *cheapest_node);
void	rev_rotate_them(t_stack_node **a_stack, t_stack_node **b_stack, t_stack_node *cheapest_node);
void	preping_to_push(t_stack_node **stack, t_stack_node *top_node, char which_one);
void	sort_stacks(t_stack_node **a_stack, t_stack_node **b_stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void	b_init_nodes(t_stack_node *a_stack, t_stack_node *b_stack);

// // --------------------

// // MOVES
void	sa(t_stack_node **a_stack);
void	sb(t_stack_node **b_stack);
int		swap(t_stack_node **stack);
void	ra(t_stack_node **a_stack, bool i);
void	rb(t_stack_node **b_stack, bool i);
void	rr(t_stack_node **a_stack, t_stack_node **b_stack);
void	pb(t_stack_node **a_stack, t_stack_node **b_stack);
void	pa(t_stack_node **a_stack, t_stack_node **b_stack);
void	rra(t_stack_node **a_stack, bool i);
void	rrb(t_stack_node **b_stack, bool i);
void	rrr(t_stack_node **a_stack, t_stack_node **b_stack);
// ------------------

#endif