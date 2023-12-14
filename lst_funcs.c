/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:49:54 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/14 15:21:50 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_lstnew(int nbr)
{
	t_stack_node	*rtn;

	rtn = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!rtn)
		return (rtn = NULL);
	rtn->next = NULL;
	rtn->nbr = nbr;
	return (rtn);
}

void	ft_lstadd_back(t_stack_node **alst, t_stack_node *new)
{
	t_stack_node	*t;

	if (*alst)
	{
		t = ft_lstlast(*alst);
		t->next = &*new;
	}
	else
		*alst = new;
}

t_stack_node	*ft_lstlast(t_stack_node *lst)
{
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize(t_stack_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
