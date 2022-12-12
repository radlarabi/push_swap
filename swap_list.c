/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:07:29 by rlarabi           #+#    #+#             */
/*   Updated: 2022/12/09 20:07:56 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_list(t_list *list, char m)
{
    int temp;
    temp = list->tab[0];
    list->tab[0] = list->tab[1];
    list->tab[1] = temp;
    if (m == 'a')
        write(1, "sa\n", 3);
    else if (m == 'b')
        write(1, "sb\n", 3);
}