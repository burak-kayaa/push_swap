/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:23:26 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/14 14:31:04 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_node_b(t_stack_node *a_stack, t_stack_node *b_stack)
{
	t_stack_node	*current_a;
	t_stack_node	*target;
	long			best_one;

	while (b_stack)
	{
		best_one = LONG_MAX;
		current_a = a_stack;
		while (current_a)
		{
			if (current_a->nbr > b_stack->nbr
				&& current_a->nbr < best_one)
			{
				best_one = current_a->nbr;
				target = current_a;		
			}
			current_a = current_a->next;
		}
		if (best_one == LONG_MAX)
			b_stack->target_node = ft_lstmin(a_stack);
		else
			b_stack->target_node = target;
		b_stack = b_stack->next;
	}
}

void	b_init_nodes(t_stack_node *a_stack, t_stack_node *b_stack)
{
	current_idx(a_stack);
	current_idx(b_stack);
	choose_node_b(a_stack, b_stack);
}