/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:13:10 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/10 17:15:35 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!a)
		return (NULL);
	a->tab = malloc(sizeof(int) * i);
	if (!(a->tab))
		return (NULL);
	a->top = -1;
	return (a);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	*get_table(t_list *a)
{
	int	i;
	int	j;
	int	*array;

	i = -1;
	array = malloc(a->top * sizeof(int));
	if (!array)
		return (NULL);
	while (++i <= a->top)
		array[i] = a->tab[i];
	i = -1;
	while (++i <= a->top)
	{
		j = -1;
		while (++j < a->top)
		{
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
		}
	}
	return (array);
}
