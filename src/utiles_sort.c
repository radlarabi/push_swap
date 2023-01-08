/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:22:12 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/08 16:14:12 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list *a)
{
	if (a->tab[a->top] > a->tab[a->top - 1])
		swap_list(a, 'a');
}

void	sort_3(t_list *a)
{
	if (a->tab[0] > a->tab[1] && a->tab[0] > a->tab[2] && a->tab[2] > a->tab[1])
		swap_list(a, 'a');
	if (a->tab[0] > a->tab[1] && a->tab[0] < a->tab[2])
		rotate_list(a, 'a');
	else if (a->tab[2] < a->tab[1] && a->tab[0] < a->tab[2])
		rotate_reverce_list(a, 'a');
	else if (a->tab[2] > a->tab[0] && a->tab[0] < a->tab[1])
	{
		swap_list(a, 'a');
		rotate_reverce_list(a, 'a');
	}
	else if (a->tab[1] > a->tab[0] && a->tab[0] > a->tab[2])
	{
		swap_list(a, 'a');
		rotate_list(a, 'a');
	}
}

void	sort_4(t_list *a, t_list *b)
{
	int	min;
	int	i;

	i = a->top;
	while (i >= 0)
	{
		min = get_min(a->tab, a->top);
		while (a->tab[a->top] != min)
			rotate_list(a, 'a');
		if (is_sorted(a))
			break ;
		push(a, b, 'b');
		i--;
	}
	i = b->top;
	while (i >= 0)
	{
		push(b, a, 'a');
		i--;
	}
}

void	sort_5(t_list *a, t_list *b)
{
	int	min;

	while (a->top != -1)
	{
		min = get_min(a->tab, a->top);
		if (get_index(a->tab, a->top, min) >= (a->top / 2))
		{
			while (a->tab[a->top] != min)
				rotate_list(a, 'a');
		}
		else if (get_index(a->tab, a->top, min) < (a->top / 2))
		{
			while (a->tab[a->top] != min)
				rotate_reverce_list(a, 'a');
		}
		if (a->top == 2)
		{
			sort_3(a);
			break ;
		}
		push(a, b, 'b');
	}
	while (b->top != -1)
		push(b, a, 'a');
}
