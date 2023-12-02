/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:22:07 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/03 01:34:33 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*tmp;

	if ((*a_stack) == NULL)
		return ;
	tmp = (*a_stack);
	(*a_stack) = (*a_stack)->next;
	tmp->next = (*b_stack);
	(*b_stack) = tmp;
	ft_putendl_fd("pb", 1);
}

void	pa(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*tmp;

	if ((*b_stack) == NULL)
		return ;
	tmp = (*b_stack);
	(*b_stack) = (*b_stack)->next;
	tmp->next = (*a_stack);
	(*a_stack) = tmp;
	ft_putendl_fd("pa", 1);
}

void	rra(t_stack **a_stack)
{
	t_stack	*last;
	t_stack	*tmp;

	last = *a_stack;
	tmp = *a_stack;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *a_stack;
	*a_stack = last;
	tmp->next = NULL;
	write(1, "rra\n", 4);
}
