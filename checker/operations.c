/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:47:08 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/08 18:47:33 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	int	*temp;

	i = 0;
	if (list->top != -1)
	{
		temp = malloc(sizeof(int) * list->top);
		temp[list->top] = list->tab[0];
		while (i < list->top)
		{
			temp[i] = list->tab[i + 1];
			i++;
		}
		i = 0;
		while (i <= list->top)
		{
			list->tab[i] = temp[i];
			i++;
		}
	}
}

void	rotate_list(t_list *list)
{
	int	i;
	int	*temp;

	i = 1;
	if (list->top != -1)
	{
		temp = malloc(sizeof(int) * list->top);
		temp[0] = list->tab[list->top];
		while (i <= list->top)
		{
			temp[i] = list->tab[i - 1];
			i++;
		}
		i = 0;
		while (i <= list->top)
		{
			list->tab[i] = temp[i];
			i++;
		}
	}
}
