/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:22:40 by burkaya           #+#    #+#             */
/*   Updated: 2024/07/02 18:13:15 by burkaya          ###   ########.fr       */
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
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;

	while (i < argc)
	{
		tmp1 = ft_strdup(argv[i]);
		if (argv[i][0] == '+')
			tmp1++;
		j = i;
		while (++j < argc)
		{
			tmp2 = ft_strdup(argv[j]);
			tmp3 = tmp2;
			if (argv[j][0] == '+')
				tmp2++;
			if (!ft_strcmp(tmp2, tmp1))
				return (free(tmp1), free(tmp3), 0);
			free(tmp2);
		}
		free(tmp1);
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
