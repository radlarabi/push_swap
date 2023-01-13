/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:22:23 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/11 21:24:41 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_list *a, t_list *b)
{
	free(a->tab);
	free(a);
	free(b->tab);
	free(b);
}

void	free_2d_table(char **t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		free(t[i]);
		i++;
	}
	free(t);
}

int	check_args(int ac, char **av)
{
	int		j;
	int		i;
	char	**temp;

	while (--ac > 0)
	{
		temp = ft_split(av[ac], ' ');
		j = -1;
		while (temp[++j])
		{
			i = -1;
			while (temp[j][++i])
			{
				if (temp[j][i + 1] != '\0' && ft_isdigit(temp[j][i])
					&& !ft_isdigit(temp[j][i + 1]) && temp[j][i + 1] != ' ')
					return (0);
			}
			if (!sub_check_args(temp[j]))
				return (0);
		}
		if (j == 0)
			return (0);
		free_2d_table(temp);
	}
	return (1);
}

int	get_min(int *a, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = 0;
	min = a[0];
	while (i <= size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (min > a[j])
				min = a[j];
			j++;
		}
		i++;
	}
	return (min);
}

int	get_index(int *a, int size, int i)
{
	int	j;

	j = 0;
	while (j <= size && i != a[j])
		j++;
	return (j);
}
