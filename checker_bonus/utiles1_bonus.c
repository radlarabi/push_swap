/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:46:17 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/11 18:45:39 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_list	*create_list(int i)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	a->tab = malloc(sizeof(int) * i);
	a->top = -1;
	return (a);
}

int	is_duplicate(t_list *a)
{
	int	i;
	int	j;

	i = 0;
	while (i <= a->top)
	{
		j = 0;
		while (j <= a->top)
		{
			if (i == j)
			{
				j++;
				continue ;
			}
			if (a->tab[i] == a->tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_list *a)
{
	int	i;
	int	j;

	i = a->top;
	while (i >= 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (a->tab[i] > a->tab[j])
				return (0);
			j--;
		}
		i--;
	}
	return (1);
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

void	free_stacks(t_list *a, t_list *b)
{
	free(a->tab);
	free(a);
	free(b->tab);
	free(b);
}
