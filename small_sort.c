/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:57:57 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/03 16:39:16 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	common_move_s4(t_stack **a_stack, t_stack **b_stack)
{
	pb(a_stack, b_stack);
	sort_3(a_stack, b_stack);
	pa(a_stack, b_stack);
}

static void	common_move_s5(t_stack **a_stack, t_stack **b_stack)
{
	int	min_value;

	pb(a_stack, b_stack);
	min_value = get_min_value(a_stack);
	sort_4(a_stack, b_stack, min_value);
	pa(a_stack, b_stack);
}

void	sort_3(t_stack **a_stack, t_stack **b_stack)
{
	if ((*a_stack)->nbr < (*a_stack)->next->nbr 
		&& (*a_stack)->nbr < (*a_stack)->next->next->nbr)
	{
		pb(a_stack, b_stack);
		sa(a_stack);
		pa(a_stack, b_stack);
	}
	else if ((*a_stack)->next->nbr < (*a_stack)->nbr 
		&& (*a_stack)->next->nbr < (*a_stack)->next->next->nbr)
	{
		if ((*a_stack)->nbr > (*a_stack)->next->next->nbr)
			ra(a_stack);
		else
			sa(a_stack);
	}
	else
	{
		if ((*a_stack)->nbr > (*a_stack)->next->nbr)
		{
			sa(a_stack);
			rra(a_stack);
		}
		else
			rra(a_stack);
	}
}

void	sort_4(t_stack **a_stack, t_stack **b_stack, int min_value)
{
	if ((*a_stack)->nbr == min_value)
		common_move_s4(a_stack, b_stack);
	else if ((*a_stack)->next->nbr == min_value)
	{
		sa(a_stack);
		common_move_s4(a_stack, b_stack);
	}
	else if ((*a_stack)->next->next->nbr == min_value)
	{
		ra(a_stack);
		ra(a_stack);
		common_move_s4(a_stack, b_stack);
	}
	else
	{
		rra(a_stack);
		common_move_s4(a_stack, b_stack);
	}
}

void	sort_5(t_stack **a_stack, t_stack **b_stack, int min_value)
{
	if ((*a_stack)->nbr == min_value)
		common_move_s5(a_stack, b_stack);
	else if ((*a_stack)->next->nbr == min_value)
	{
		sa(a_stack);
		common_move_s5(a_stack, b_stack);
	}
	else if ((*a_stack)->next->next->nbr == min_value)
	{
		ra(a_stack);
		ra(a_stack);
		common_move_s5(a_stack, b_stack);
	}
	else if ((*a_stack)->next->next->next->nbr)
	{
		rra(a_stack);
		rra(a_stack);
		common_move_s5(a_stack, b_stack);
	}
	else
	{
		rra(a_stack);
		common_move_s5(a_stack, b_stack);
	}
}
