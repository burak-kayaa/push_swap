/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:22:49 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/03 01:32:07 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(int argc, char **argv)
{
	if (!(is_nbr(argc, argv) && is_in_limit(argc, argv) && is_dupe(argv, argc)))
	{
		printf("error\n");
		exit(0);
	}
}

void	get_nums(t_stack **a_stack, int argc, char **argv)
{
	t_stack	*new;
	char	**args;
	int		i;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		(void)args;
		return ;
	}
	i = 1;
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(a_stack, new);
		i++;
	}
}

int	is_sorted(t_stack **a_stack)
{
	t_stack	*t;

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
	t_stack	**a_stack;
	t_stack	**b_stack;

	checker(argc, argv);
	a_stack = (t_stack **)malloc(sizeof(t_stack *));
	b_stack = (t_stack **)malloc(sizeof(t_stack *));
	if (!a_stack || !b_stack)
		return (free(a_stack), free(b_stack), 0);
	get_nums(a_stack, argc, argv);
	if (is_sorted(a_stack))
	{
		free(a_stack);
		free(b_stack);
		return (0);
	}
	sort_list(a_stack, b_stack);
	return (1);
}
