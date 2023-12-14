/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:49:54 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/14 14:30:12 by burkaya          ###   ########.fr       */
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

t_stack_node	*ft_lstmax(t_stack_node *lst)
{
	long			max;
	t_stack_node	*max_node;

	if (!lst)
		return (NULL);
	max = LONG_MIN;
	while (lst)
	{
		if (lst->nbr > max)
		{
			max = lst->nbr;
			max_node = lst;
		}
		lst = lst->next;
	}
	return (max_node);
}

t_stack_node	*ft_lstmin(t_stack_node *lst)
{
	long			min;
	t_stack_node	*min_node;

	if (!lst)
		return (NULL);
	min = LONG_MAX;
	while (lst)
	{
		if (lst->nbr < min)
		{
			min = lst->nbr;
			min_node = lst;
		}
		lst = lst->next;
	}
	return (min_node);
}