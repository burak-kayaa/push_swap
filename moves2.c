/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:22:07 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/14 14:21:59 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack_node **a_stack, t_stack_node **b_stack)
{
	t_stack_node	*tmp;

	if ((*a_stack) == NULL)
		return ;
	tmp = (*a_stack);
	(*a_stack) = (*a_stack)->next;
	tmp->next = (*b_stack);
	(*b_stack) = tmp;
	ft_putendl_fd("pb", 1);
}

void	pa(t_stack_node **a_stack, t_stack_node **b_stack)
{
	t_stack_node	*tmp;

	if ((*b_stack) == NULL)
		return ;
	tmp = (*b_stack);
	(*b_stack) = (*b_stack)->next;
	tmp->next = (*a_stack);
	(*a_stack) = tmp;
	ft_putendl_fd("pa", 1);
}

void	rra(t_stack_node **a_stack, bool i)
{
	t_stack_node	*last;
	t_stack_node	*tmp;

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
	if (i == true)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack_node **b_stack, bool i)
{
	t_stack_node	*last;
	t_stack_node	*tmp;

	last = *b_stack;
	tmp = *b_stack;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *b_stack;
	*b_stack = last;
	tmp->next = NULL;
	if (i == true)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack_node **a_stack, t_stack_node **b_stack)
{
	rra(a_stack, 0);
	rrb(b_stack, 0);
	ft_putendl_fd("rrr", 1);
}