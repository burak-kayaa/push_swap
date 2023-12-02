/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:03:39 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/03 01:35:50 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack **a_stack, t_stack **b_stack, int l_size)
{
	(void)b_stack;
	if (l_size == 1)
	{
		printf("%d\n", (*a_stack)->nbr);
		exit(1);
	}
	else if (l_size == 2)
	{
		if ((*a_stack)->next->nbr > (*a_stack)->nbr)
			sa(a_stack);
	}
	else if (l_size == 3)
		sort_3(a_stack, b_stack);
	// else if (l_size == 4)
	// 	sort_4(a_stack, b_stack);
	// else if (l_size == 5)
	// 	sort_5(a_stack, b_stack);
}

void	sort_list(t_stack **a_stack, t_stack **b_stack)
{
	int	l_size;

	l_size = ft_lstsize(*a_stack);
	if (l_size <= 5)
		small_sort(a_stack, b_stack, l_size);
	// else
	// 	quick_sort();
}
