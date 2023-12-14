/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:50:34 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/14 15:27:04 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a_stack)
{
	t_stack_node	*head;
	t_stack_node	*next;
	int				tmp;

	if (!(*a_stack))
		exit(0);
	head = *a_stack;
	next = head->next;
	if (ft_lstsize(*a_stack) < 2)
		return ;
	tmp = head->nbr;
	head->nbr = next->nbr;
	next->nbr = tmp;
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack_node **b_stack)
{
	t_stack_node	*head;
	t_stack_node	*next;
	int				tmp;

	if (!(*b_stack))
		exit(0);
	head = *b_stack;
	next = head->next;
	if (ft_lstsize(*b_stack) < 2)
		return ;
	tmp = head->nbr;
	head->nbr = next->nbr;
	next->nbr = tmp;
	ft_putendl_fd("sb", 1);
}

void	ra(t_stack_node **a_stack, bool i)
{
	t_stack_node	*last;
	t_stack_node	*first;

	if (*a_stack == NULL || (*a_stack)->next == NULL)
		return ;
	last = *a_stack;
	first = *a_stack;
	while (last->next)
		last = last->next;
	(*a_stack) = first->next;
	first->next = NULL;
	last->next = first;
	if (i == true)
		ft_putendl_fd("ra", 1);
	return ;
}

void	rb(t_stack_node **b_stack, bool i)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (*b_stack == NULL || (*b_stack)->next == NULL)
		return ;
	last = *b_stack;
	first = *b_stack;
	while (last->next)
		last = last->next;
	(*b_stack) = first->next;
	first->next = NULL;
	last->next = first;
	if (i == true)
		ft_putendl_fd("rb", 1);
	return ;
}

void	rr(t_stack_node **a_stack, t_stack_node **b_stack)
{
	ra(a_stack, false);
	rb(b_stack, false);
	ft_putendl_fd("rr", 1);
}
