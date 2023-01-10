/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:40:55 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/10 17:16:50 by rlarabi          ###   ########.fr       */
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
			free_2d_table(temp);
		}
		i++;
		free_2d_table(ret);
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
		free_2d_table(ret);
	}
	else if (ac > 2)
		init_stacks(a, b, ac, av);
}

int	read_result(t_list *a, t_list *b)
{
	char	*temp;
	int		i;

	i = 0;
	while (1)
	{
		temp = get_next_line(0);
		if (temp == NULL)
			break ;
		read_op1(a, b, temp);
		if (!read_op2(a, b, temp))
		{
			return (0);
		}
		free(temp);
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
