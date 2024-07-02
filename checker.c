/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:22:40 by burkaya           #+#    #+#             */
/*   Updated: 2024/07/02 18:28:19 by burkaya          ###   ########.fr       */
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
			if (argv[i][0] == '-' || argv[i][0] == '+')
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
	int		j;
	t_tmps	tmps;

	while (i < argc)
	{
		tmps.tmp1 = ft_strdup(argv[i]);
		tmps.tmp4 = tmps.tmp1;
		if (argv[i][0] == '+')
			tmps.tmp1++;
		j = i;
		while (++j < argc)
		{
			tmps.tmp2 = ft_strdup(argv[j]);
			tmps.tmp3 = tmps.tmp2;
			if (argv[j][0] == '+')
				tmps.tmp2++;
			if (!ft_strcmp(tmps.tmp2, tmps.tmp1))
				return (free(tmps.tmp4), free(tmps.tmp3), 0);
			free(tmps.tmp2);
		}
		free(tmps.tmp4);
		i++;
	}
	return (1);
}

int	is_in_limit(int argc, char **argv, int i)
{
	int		tmp;
	char	*check;
	char	*tmp_str;

	while (i <= argc - 1)
	{
		tmp = ft_atoi(argv[i]);
		tmp_str = ft_itoa(tmp);
		if (argv[i][0] == '+')
			check = ft_strjoin("+", tmp_str);
		else
			check = ft_strdup(tmp_str);
		if (ft_strcmp(check, argv[i]))
		{
			free(check);
			free(tmp_str);
			return (0);
		}
		free(tmp_str);
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
