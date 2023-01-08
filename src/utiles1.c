/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:13:10 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/06 15:16:09 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_list(t_list *a)
{
	int	i;

	i = a->top;
	while (i >= 0)
	{
		printf("%d\n", a->tab[i]);
		i--;
	}
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

t_list	*create_list(int i)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	a->tab = malloc(sizeof(int) * i);
	a->top = -1;
	return (a);
}

int	*get_table(t_list *a)
{
	int	i;
	int	j;
	int	*array;
	int	temp;

	i = -1;
	if (a->top != -1)
		array = malloc(a->top * sizeof(int));
	while (++i <= a->top)
		array[i] = a->tab[i];
	i = -1;
	while (++i <= a->top)
	{
		j = -1;
		while (++j < a->top)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	return (array);
}
