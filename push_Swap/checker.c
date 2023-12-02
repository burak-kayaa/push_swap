/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:22:40 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/03 01:32:17 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_nbr(int argc, char **argv)
{
	int		i;
	int		j;
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		i = 0;
	}
	else
	{
		args = argv;	
		i = 1;
	}
	while (i < argc)
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][0] == '-')
			{
				j++;
				break ;
			}
			if (args[i][j] <= '9' && args[i][j] >= '0')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_dupe(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
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

int	is_in_limit(int argc, char **argv)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < argc - 1)
	{
		tmp = ft_atoi(argv[i + 1]);
		if (ft_strcmp(ft_itoa(tmp), argv[i + 1]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
