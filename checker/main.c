/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:40:55 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/08 21:34:02 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	read_result(t_list *a, t_list *b)
{
	char	*temp;

	while (1)
	{
		temp = get_next_line(0);
		if (temp == NULL)
			break ;
		read_op1(a, b, temp);
		if (!read_op2(a, b, temp))
			return (0);
	}
	return (1);
}

void	print_result(t_list *a, t_list *b)
{
	if (is_sorted(a) && b->top == -1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
	if (!read_result(a, b))
		return (0);
	print_result(a, b);
	free_stacks(a, b);
	return (0);
}
