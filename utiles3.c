/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:22:23 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/08 15:56:54 by rlarabi          ###   ########.fr       */
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
			if ((ft_atoi(temp[j]) == -1 && ft_strncmp(temp[j], "-1", 2) != 0)
				|| (ft_atoi(temp[j]) == 0 && ft_strncmp(temp[j], "0", 1) != 0
					&& ft_strncmp(temp[j], "+0", 2) != 0 && ft_strncmp(temp[j],
						"-0", 2) != 0))
				return (0);
		}
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

void	sub_push_a_b(t_list *a, int *array_sorted, int start, int end)
{
	if (calcule_steps(a, array_sorted, start, end))
		rotate_list(a, 'a');
	else
		rotate_reverce_list(a, 'a');
}
