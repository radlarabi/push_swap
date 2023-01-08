/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:41:17 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/08 20:39:10 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	count_args(int ac, char **av, int count)
{
	char	**ret;
	char	**temp;
	int		i;
	int		k;
	int		j;

	i = 0;
	while (i < ac - 1)
	{
		ret = ft_split(av[i + 1], ' ');
		j = 0;
		while (ret[j])
		{
			temp = ft_split(ret[j], ' ');
			k = 0;
			while (temp[k++])
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	sort_cases(t_list *a, t_list *b)
{
	if (a->top == 1)
		sort_2(a);
	else if (a->top == 2)
		sort_3(a);
	else if (a->top == 3)
		sort_4(a, b);
	else if (a->top == 4)
		sort_5(a, b);
	else if (a->top >= 5 && a->top <= 9)
		sort_4(a, b);
	else if (a->top >= 10 && a->top <= 99)
		small_sort(a, b);
	else if (a->top > 99)
		big_sort(a, b);
}

void	remplire_stacks(t_list *a, t_list *b, int ac, char **av)
{
	int		i;
	char	**ret;

	i = count_args(ac, av, 0);
	if (ac == 2)
	{
		ret = ft_split(av[1], ' ');
		while (i > 0)
			a->tab[++a->top] = ft_atoi(ret[--i]);
		free(ret);
	}
	else if (ac > 2)
		init_stacks(a, b, ac, av);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	**ret;

	if (ac == 1)
		return (0);
	if (!check_args(ac, av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	a = create_list(count_args(ac, av, 0));
	b = create_list(count_args(ac, av, 0));
	remplire_stacks(a, b, ac, av);
	if (is_duplicate(a))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else if (is_sorted(a))
		return (0);
	sort_cases(a, b);
	free_stacks(a, b);
	return (0);
}
