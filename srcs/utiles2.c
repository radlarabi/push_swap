/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:15:02 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/09 22:08:43 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_list(int *a, int size)
{
	int	max;
	int	i;

	max = a[0];
	i = 1;
	while (i < size)
	{
		if (a[i] > max)
			max = a[i];
		i++;
	}
	return (max);
}

int	get_max_list_without(int *a, int size, int exept)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	while (i < size)
	{
		if (a[i] == exept)
		{
			i++;
			continue ;
		}
		if (a[i] > max)
			max = a[i];
		i++;
	}
	return (max);
}

int	if_exist(t_list *a, int *arr, int start, int end)
{
	int	i;

	i = 0;
	while (i <= a->top)
	{
		if (a->tab[i] >= arr[start] && a->tab[i] <= arr[end])
			return (1);
		i++;
	}
	return (0);
}

int	calcule_steps(t_list *a, int *array_sorted, int start, int end)
{
	int	i;
	int	j;

	i = 0;
	while (i <= a->top)
	{
		if (a->tab[i] >= array_sorted[start] && a->tab[i] <= array_sorted[end])
			break ;
		i++;
	}
	j = a->top;
	while (j >= 0)
	{
		if (a->tab[j] >= array_sorted[start] && a->tab[j] <= array_sorted[end])
			break ;
		j--;
	}
	if (i >= a->top - j)
		return (1);
	else
		return (0);
}
