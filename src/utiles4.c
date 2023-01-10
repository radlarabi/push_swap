/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:25:54 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/10 16:55:45 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sub_push_a_b(t_list *a, int *array_sorted, int start, int end)
{
	if (calcule_steps(a, array_sorted, start, end))
		rotate_list(a, 'a');
	else
		rotate_reverce_list(a, 'a');
}

int	change_chunk_big(int start, int end, int size, char a)
{
	int	offset;

	offset = (size + 1) / 12;
	if (a == 's')
	{
		start -= offset;
		if (start < 0)
			start = 0;
		return (start);
	}
	else
	{
		end += offset;
		if (end >= size)
			end = size;
		return (end);
	}
}

int	change_chunk_small(int start, int end, int size, char a)
{
	int	offset;

	offset = (size + 1) / 8;
	if (a == 's')
	{
		start -= offset;
		if (start < 0)
			start = 0;
		return (start);
	}
	else
	{
		end += offset;
		if (end >= size)
			end = size;
		return (end);
	}
}

int	sub_check_args(char *temp)
{
	if ((ft_atoi(temp) == -1 && ft_strncmp(temp, "-1", 2) != 0)
		|| (ft_atoi(temp) == 0 && ft_strncmp(temp, "0", 1) != 0
			&& ft_strncmp(temp, "+0", 2) != 0 && ft_strncmp(temp, "-0",
				2) != 0))
		return (0);
	else
		return (1);
}
