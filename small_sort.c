/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:11:56 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/02 15:20:12 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calcule_steps(t_list *a, t_list *b, int *array_sorted, int start, int end)
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

void	push_a_b(t_list *a, t_list *b, int start, int end, int *array_sorted)
{
    int mid;

    mid = ((a->top + 1) / 2) - 1;
	while (if_exist(a->tab, a->top + 1, array_sorted, start, end))
	{
		if (a->tab[a->top] >= array_sorted[start]
			&& a->tab[a->top] <= array_sorted[end])
		{
			push(a, b, 'b');
			if (b->tab[b->top] <= array_sorted[mid]
            && b->top != 0 && b->top != -1)
				rotate_list(b, 'b');
		}
		else
		{
			if (calcule_steps(a, b, array_sorted, start, end))
				rotate_list(a, 'a');
			else
				rotate_reverce_list(a, 'a');
		}
	}
}

void	push_b_a(t_list *a, t_list *b)
{
	int	i;
	int	max;

	i = b->top;
	while (i >= 0)
	{
		max = get_max_list(b->tab, b->top + 1);
		if (get_index(b->tab, b->top, max) > (b->top / 2))
		{
			while (b->tab[b->top] != max)
				rotate_list(b, 'b');
		}
		else
		{
			while (b->tab[b->top] != max)
				rotate_reverce_list(b, 'b');
		}
		push(b, a, 'a');
		i--;
	}
}

void	small_sort(t_list *a, t_list *b)
{
	int	*array_sorted;
	int	mid;
	int	offset;
	int	start;
	int	end;

	array_sorted = get_table(a);
	mid = ((a->top + 1) / 2) - 1;
	offset = (a->top + 1) / 8;
	start = mid - offset;
	end = mid + offset;
	while (a->top != -1)
	{
		push_a_b(a, b, start, end, array_sorted);
		start -= offset;
		end += offset;
	}
	push_b_a(a, b);
}
