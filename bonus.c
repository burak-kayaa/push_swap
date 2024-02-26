/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:00:17 by burkaya           #+#    #+#             */
/*   Updated: 2024/02/26 18:04:32 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_move(t_stack_node **a_stack, t_stack_node **b_stack, char *move)
{
	if (!ft_strcmp("sa\n", move))
		sa(a_stack, 0);
	else if (!ft_strcmp("sb\n", move))
		sb(b_stack, 0);
	else if (!ft_strcmp("sb\n", move))
		sb(b_stack, 0);
	else if (!ft_strcmp("ra\n", move))
		ra(a_stack, 0);
	else if (!ft_strcmp("rb\n", move))
		rb(b_stack, 0);
	else if (!ft_strcmp("rr\n", move))
		rr(a_stack, b_stack, 0);
	else if (!ft_strcmp("pb\n", move))
		pb(a_stack, b_stack, 0);
	else if (!ft_strcmp("pa\n", move))
		pa(a_stack, b_stack, 0);
	else if (!ft_strcmp("rra\n", move))
		rra(a_stack, 0);
	else if (!ft_strcmp("rrb\n", move))
		rrb(b_stack, 0);
	else if (!ft_strcmp("rrr\n", move))
		rrr(a_stack, b_stack, 0);
	else
		(ft_printf("Error\n"), exit(0));
}

char	**checker(int argc, char **argv)
{
	char	**split;
	int		elems;

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		elems = ft_count(split);
		if (!(is_nbr(elems, split, 0) && is_in_limit(elems, split, 0)
				&& is_dupe(split, elems, 0)))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		return (split);
	}
	else if (!(is_nbr(argc, argv, 1) && is_in_limit(argc, argv, 1)
			&& is_dupe(argv, argc, 1)))
	{
		write(2, "Error\n", 6);
		exit(0);
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

int	main(int argc, char **argv)
{
	t_stack_node	*a_stack;
	t_stack_node	*b_stack;
	char			*move;

	if (!argv[1] || !argv[1][0])
		exit(0);
	a_stack = NULL;
	b_stack = NULL;
	argv = checker(argc, argv);
	get_nums(&a_stack, argc, argv);
	move = get_next_line(0);
	if (is_sorted(&a_stack))
		return (ft_free(&a_stack), ft_printf("OK\n"), 0);
	while (move)
	{
		do_move(&a_stack, &b_stack, move);
		free(move);
		move = get_next_line(0);
	}
	if (is_sorted(&a_stack) && !b_stack)
		return (ft_free(&a_stack), ft_printf("OK\n"), 1);
	else
		return (ft_free(&a_stack), ft_printf("KO\n"), 1);
}
