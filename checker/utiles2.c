/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:58:45 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/08 21:32:33 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_op1(t_list *a, t_list *b, char *temp)
{
	if (!ft_strncmp(temp, "ra", 2))
		rotate_list(a);
	else if (!ft_strncmp(temp, "rra", 3))
		rotate_reverce_list(a);
	else if (!ft_strncmp(temp, "rb", 2))
		rotate_list(b);
	else if (!ft_strncmp(temp, "rrb", 3))
		rotate_reverce_list(b);
	else if (!ft_strncmp(temp, "sa", 2))
		swap_list(a);
	else if (!ft_strncmp(temp, "sb", 2))
		swap_list(b);
	else if (!ft_strncmp(temp, "ss", 2))
	{
		swap_list(a);
		swap_list(b);
	}
}

int	read_op2(t_list *a, t_list *b, char *temp)
{
	if (!ft_strncmp(temp, "pa", 2))
		push(b, a);
	else if (!ft_strncmp(temp, "pb", 2))
		push(a, b);
	else if (!ft_strncmp(temp, "rr", 2))
	{
		rotate_list(a);
		rotate_list(b);
	}
	else if (!ft_strncmp(temp, "rrr", 3))
	{
		rotate_reverce_list(a);
		rotate_reverce_list(b);
	}
	else
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

void	init_stacks(t_list *a, t_list *b, int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	char	**temp;

	i = 0;
	j = ac - 1;
	while (i < ac - 1)
	{
		temp = ft_split(av[j--], ' ');
		k = 0;
		while (temp[k])
			k++;
		k--;
		while (k >= 0)
			a->tab[++a->top] = ft_atoi(temp[k--]);
		i++;
	}
	free(temp);
}
