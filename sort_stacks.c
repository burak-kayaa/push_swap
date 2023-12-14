/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:58:27 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/14 15:14:59 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_stack_node **a_stack, t_stack_node **b_stack)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a_stack);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_them(a_stack, b_stack, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_them(a_stack, b_stack, cheapest_node);
	preping_to_push(a_stack, cheapest_node, 'a');
	preping_to_push(b_stack, cheapest_node->target_node, 'b');
	pb(a_stack, b_stack);
}

static void	push_to_a(t_stack_node **a_stack, t_stack_node **b_stack)
{
	preping_to_push(a_stack, (*b_stack)->target_node, 'a');
	pa(a_stack, b_stack);
}

static void	min_to_top(t_stack_node **a_stack)
{
	while ((*a_stack)->nbr != ft_lstmin(*a_stack)->nbr)
	{
		if (ft_lstmin(*a_stack)->above_median)
			ra(a_stack, true);
		else
			rra(a_stack, true);
	}
}

void	sort_stacks(t_stack_node **a_stack, t_stack_node **b_stack)
{
	int	a_len;

	a_len = ft_lstsize(*a_stack);
	if (a_len-- > 3 && !is_sorted(a_stack))
		pb(a_stack, b_stack);
	if (a_len-- > 3 && !is_sorted(a_stack))
		pb(a_stack, b_stack);
	while (a_len-- > 3 && !is_sorted(a_stack))
	{
		a_init_nodes(*a_stack, *b_stack);
		push_to_b(a_stack, b_stack);
	}
	sort_3(a_stack);
	while (*b_stack)
	{
		b_init_nodes(*a_stack, *b_stack);
		push_to_a(a_stack, b_stack);
	}
	current_idx(*a_stack);
	min_to_top(a_stack);
}
