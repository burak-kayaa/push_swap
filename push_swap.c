/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:22:49 by burkaya           #+#    #+#             */
/*   Updated: 2024/07/02 18:29:21 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**checker(int argc, char **argv)
{
	char	**split;
	int		elems;

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		elems = ft_count(split);
		if (elems == 0 || !(is_nbr(elems, split, 0)
				&& is_in_limit(elems, split, 0) && is_dupe(split, elems, 0)))
		{
			ft_free_split(split, elems);
			write(2, "Error\n", 6);
			exit(1);
		}
		return (split);
	}
	else if (!(is_nbr(argc, argv, 1) && is_in_limit(argc, argv, 1)
			&& is_dupe(argv, argc, 1)))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (argv);
}

void	get_nums(t_stack_node **a_stack, int argc, char **argv)
{
	t_stack_node	*new;
	int				i;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(a_stack, new);
		i++;
	}
	if (argc == 2)
	{
		i = -1;
		while (argv[++i])
			free(argv[i]);
		free(argv);
	}
}

int	is_sorted(t_stack_node **a_stack)
{
	t_stack_node	*t;

	t = *a_stack;
	while (t->next)
	{
		if (t->nbr < t->next->nbr)
			t = t->next;
		else
			return (0);
	}
	return (1);
}

void	init_a(t_stack_node *stack)
{
	while (stack)
	{
		stack->cheapest = false;
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a_stack;
	t_stack_node	*b_stack;

	if (argc == 1)
		return (0);
	if (!argv[1] || !argv[1][0])
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	a_stack = NULL;
	b_stack = NULL;
	argv = checker(argc, argv);
	get_nums(&a_stack, argc, argv);
	init_a(a_stack);
	if (is_sorted(&a_stack))
	{
		ft_free(&a_stack);
		return (0);
	}
	sort_list(&a_stack, &b_stack);
	ft_free(&a_stack);
	return (1);
}
