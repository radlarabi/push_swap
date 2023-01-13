/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:28:14 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/11 19:58:26 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	sub_read_result(t_list *a, t_list *b, char *temp)
{
	if (ft_strlen(temp) == 3)
	{
		if (!read_op1(a, b, temp))
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	else if (ft_strlen(temp) == 4)
	{
		if (!read_op2(a, b, temp))
			return (0);
	}
	else
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
