/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:05:34 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/18 18:37:31 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_them(t_stack_node **a_stack, t_stack_node **b_stack, \
t_stack_node *cheapest_node)
{
	while (*b_stack != cheapest_node->target_node && *a_stack != cheapest_node)
		rr(a_stack, b_stack);
	current_idx(*a_stack);
	current_idx(*b_stack);
}

void	rev_rotate_them(t_stack_node **a_stack, t_stack_node **b_stack, \
t_stack_node *cheapest_node)
{
	while (*b_stack != cheapest_node->target_node && *a_stack != cheapest_node)
		rrr(a_stack, b_stack);
	current_idx(*a_stack);
	current_idx(*b_stack);
}

void	preping_to_push(t_stack_node **stack, t_stack_node *top_node, \
char which_one)
{
	while (*stack != top_node)
	{
		if (which_one == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (which_one == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}
