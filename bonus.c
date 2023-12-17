/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:00:17 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/17 20:38:46 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_move(t_stack_node **a_stack, t_stack_node **b_stack, char *move)
{
	if (!ft_strcmp("sa", move))
		sa(a_stack);
	else if (!ft_strcmp("sb", move))
		sb(b_stack);
	else if (!ft_strcmp("sb", move))
		sb(b_stack);
	else if (!ft_strcmp("ra", move))
		ra(a_stack, 0);
	else if (!ft_strcmp("rb", move))
		rb(b_stack, 0);
	else if (!ft_strcmp("rr", move))
		rr(a_stack, b_stack);
	else if (!ft_strcmp("pb", move))
		pb(a_stack, b_stack);
	else if (!ft_strcmp("pa", move))
		pa(a_stack, b_stack);
	else if (!ft_strcmp("rra", move))
		rra(a_stack, 0);
	else if (!ft_strcmp("rrb", move))
		rrb(b_stack, 0);
	else if (!ft_strcmp("rrr", move))
		rrr(a_stack, b_stack);
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
			ft_printf("error\n");
			exit(0);
		}
		return (split);
	}
	else if (!(is_nbr(argc, argv, 1) && is_in_limit(argc, argv, 1) 
			&& is_dupe(argv, argc, 1)))
	{
		ft_printf("error\n");
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

	a_stack = NULL;
	b_stack = NULL;
	argv = checker(argc, argv);
	get_nums(&a_stack, argc, argv);
	if (is_sorted(&a_stack))
		return (ft_free(&a_stack), 0);
	move = get_next_line(0);
	sort_stacks(&a_stack, &b_stack);
	ft_printf("%s\n", move);
	while (move)
	{
		do_move(&a_stack, &b_stack, move);
		free(move);
		move = get_next_line(0);
	}
	if (is_sorted(&a_stack))
	{
		if (!b_stack)
			ft_printf("OK\n");
	}
	else
		ft_printf("KO\n");
}
