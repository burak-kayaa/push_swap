/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:03:39 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/14 15:35:48 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack_node **a_stack)
{
	t_stack_node	*biggest;

	biggest = ft_lstmax(*a_stack);
	if (biggest == *a_stack)
		ra(a_stack, true);
	else if ((*a_stack)->next == biggest)
		rra(a_stack, true);
	if ((*a_stack)->nbr > (*a_stack)->next->nbr)
		sa(a_stack);
}

int	get_min_value(t_stack_node **a_stack)
{
	t_stack_node	*tmp;
	int				min;

	tmp = *a_stack;
	min = tmp->nbr;
	while (tmp)
	{
		if (min > tmp->nbr)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	return (min);
}

void	small_sort(t_stack_node **a_stack, int l_size)
{
	if (l_size == 1)
	{
		ft_printf("%d\n", (*a_stack)->nbr);
		exit(1);
	}
	else if (l_size == 2)
		sa(a_stack);
	else if (l_size == 3)
		sort_3(a_stack);
}

void	sort_list(t_stack_node **a_stack, t_stack_node **b_stack)
{
	int	l_size;

	l_size = ft_lstsize(*a_stack);
	if (l_size <= 3)
		small_sort(a_stack, l_size);
	else
		sort_stacks(a_stack, b_stack);
}
