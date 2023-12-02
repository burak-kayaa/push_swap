/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:57:57 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/03 01:00:43 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
