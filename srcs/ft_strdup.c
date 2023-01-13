/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:56:44 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/11 14:54:39 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	a = (char *) malloc(i * sizeof(char) + 1);
	if (!a)
		return (0);
	i = -1;
	while (s1[++i])
		a[i] = s1[i];
	a[i] = '\0';
	return (a);
}
