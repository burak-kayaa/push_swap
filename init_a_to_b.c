/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:03:37 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/18 19:30:07 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_idx(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->idx = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	choose_node_a(t_stack_node *a_stack, t_stack_node *b_stack)
{
	t_stack_node	*current_b;
	t_stack_node	*target;
	long			best_one;

	while (a_stack)
	{
		best_one = LONG_MIN;
		current_b = b_stack;
		while (current_b)
		{
			if (current_b->nbr < a_stack->nbr
				&& current_b->nbr > best_one)
			{
				best_one = current_b->nbr;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_one == LONG_MIN)
			a_stack->target_node = ft_lstmax(b_stack);
		else
			a_stack->target_node = target;
		a_stack = a_stack->next;
	}
}

void	calc_moves(t_stack_node *a_stack, t_stack_node *b_stack)
{
	int	a_len;
	int	b_len;

	a_len = ft_lstsize(a_stack);
	b_len = ft_lstsize(b_stack);
	while (a_stack)
	{
		a_stack->push_cost = a_stack->idx;
		if (!(a_stack->above_median))
			a_stack->push_cost = a_len - (a_stack->idx);
		if (a_stack->target_node->above_median)
			a_stack->push_cost += a_stack->target_node->idx;
		else
			a_stack->push_cost += b_len - (a_stack->target_node->idx);
		a_stack = a_stack->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			cheapest;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	a_init_nodes(t_stack_node *a_stack, t_stack_node *b_stack)
{
	current_idx(a_stack);
	current_idx(b_stack);
	choose_node_a(a_stack, b_stack);
	calc_moves(a_stack, b_stack);
	set_cheapest(a_stack);
}
