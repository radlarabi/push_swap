/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:11:56 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/11 21:26:30 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_to_b(t_list *a, t_list *b, int start, int end)
{
	int	mid;
	int	size;
	int	*array_sorted;

	size = a->top;
	array_sorted = get_table(a);
	mid = ((a->top + 1) / 2) - 1;
	while (a->top != -1)
	{
		while (if_exist(a, array_sorted, start, end))
		{
			if (a->tab[a->top] >= array_sorted[start]
				&& a->tab[a->top] <= array_sorted[end])
			{
				push(a, b, 'b');
				if (b->tab[b->top] <= array_sorted[mid])
					rotate_list(b, 'b');
			}
			else
				sub_push_a_b(a, array_sorted, start, end);
		}
		start = change_chunk_small(start, end, size, 's');
		end = change_chunk_small(start, end, size, 'e');
	}
	free(array_sorted);
}

int	rotate1(t_list *a, t_list *b, int max, int down)
{
	while (b->tab[b->top] != max && b->top != -1)
	{
		if (a->tab[0] < b->tab[b->top] || down == 0)
		{
			push(b, a, 'a');
			rotate_list(a, 'a');
			down++;
		}
		else
			rotate_list(b, 'b');
	}
	return (down);
}

int	rotate_reverce1(t_list *a, t_list *b, int max, int down)
{
	while (b->tab[b->top] != max && b->top != -1)
	{
		if (a->tab[0] < b->tab[b->top] || down == 0)
		{
			push(b, a, 'a');
			rotate_list(a, 'a');
			down++;
		}
		else
			rotate_reverce_list(b, 'b');
	}
	return (down);
}

void	push_b_to_a(t_list *a, t_list *b)
{
	int	max;
	int	down;

	down = 0;
	while (b->top != -1)
	{
		max = get_max_list(b->tab, b->top + 1);
		if (get_index(b->tab, b->top, max) > (b->top / 2))
			down = rotate1(a, b, max, down);
		else
			down = rotate_reverce1(a, b, max, down);
		while (a->tab[0] > b->tab[b->top] && down != 0)
		{
			down--;
			rotate_reverce_list(a, 'a');
		}
		push(b, a, 'a');
	}
	while (down != 0)
	{
		down--;
		rotate_reverce_list(a, 'a');
	}
}

void	small_sort(t_list *a, t_list *b)
{
	int	mid;
	int	offset;

	mid = ((a->top + 1) / 2) - 1;
	offset = (a->top + 1) / 8;
	push_a_to_b(a, b, mid - offset, mid + offset);
	push_b_to_a(a, b);
}
