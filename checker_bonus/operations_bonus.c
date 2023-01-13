/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:47:08 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/11 19:58:54 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_list(t_list *list)
{
	int	temp;
	int	top;

	top = list->top;
	if (list->top != -1 && list->top != 0)
	{
		temp = list->tab[top];
		list->tab[top] = list->tab[top - 1];
		list->tab[top - 1] = temp;
	}
}

void	push(t_list *a, t_list *b)
{
	if (a->top != -1)
	{
		b->tab[++b->top] = a->tab[a->top--];
	}
}

void	rotate_reverce_list(t_list *list)
{
	int	i;
	int	temp;

	if (list->top != -1)
	{
		i = 0;
		temp = list->tab[0];
		while (i < list->top)
		{
			list->tab[i] = list->tab[i + 1];
			i++;
		}
		list->tab[list->top] = temp;
	}
}

void	rotate_list(t_list *list)
{
	int	i;
	int	temp;

	if (list->top != -1)
	{
		i = list->top;
		temp = list->tab[list->top];
		while (i > 0)
		{
			list->tab[i] = list->tab[i - 1];
			i--;
		}
		list->tab[0] = temp;
	}
}
