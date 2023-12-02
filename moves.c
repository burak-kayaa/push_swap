/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:50:34 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/03 01:32:59 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	int		tmp;
	t_stack	*head;
	t_stack	*next;

	head = *stack;
	next = head->next;
	if (ft_lstsize(*stack) < 2)
		return (0);
	tmp = head->nbr;
	head->nbr = next->nbr;
	next->nbr = tmp;
	return (1);
}

void	sa(t_stack **a_stack)
{
	if (!(*a_stack))
		exit(0);
	swap(a_stack);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **b_stack)
{
	if (!(*b_stack))
		exit(0);
	swap(b_stack);
	ft_putendl_fd("sb", 1);
}

void	ra(t_stack **a_stack)
{
	t_stack	*last;
	t_stack	*first;

	if (*a_stack == NULL || (*a_stack)->next == NULL)
		return ;
	last = *a_stack;
	first = *a_stack;
	while (last->next)
		last = last->next;
	(*a_stack) = first->next;
	first->next = NULL;
	last->next = first;
	ft_putendl_fd("ra", 1);
	return ;
}

void	rb(t_stack **b_stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*b_stack == NULL || (*b_stack)->next == NULL)
		return ;
	last = *b_stack;
	first = *b_stack;
	while (last->next)
		last = last->next;
	(*b_stack) = first->next;
	first->next = NULL;
	last->next = first;
	ft_putendl_fd("rb", 1);
	return ;
}
