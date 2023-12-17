/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:22:40 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/17 18:14:24 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	is_nbr(int argc, char **argv, int i)
{
	int		j;

	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][0] == '-')
			{
				j++;
				break ;
			}
			if (argv[i][j] <= '9' && argv[i][j] >= '0')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_dupe(char **argv, int argc, int i)
{
	int	j;

	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strncmp(argv[j], argv[i], sizeof(argv[j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_in_limit(int argc, char **argv, int i)
{
	int		tmp;
	char	*check;

	while (i < argc - 1)
	{
		tmp = ft_atoi(argv[i + 1]);
		check = ft_itoa(tmp);
		if (ft_strcmp(check, argv[i + 1]))
		{
			free(check);
			return (0);
		}
		free(check);
		i++;
	}
	return (1);
}

void	ft_free(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
