/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverce_rotate_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:31:44 by rlarabi           #+#    #+#             */
/*   Updated: 2022/12/11 20:43:59 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_reverce_list(t_list *list, char m)
{
    int i = 1;
    int *temp;

    temp = malloc(sizeof(int) * list->size);
    temp[0] = list->tab[list->size - 1];
    while (i < list->size)
    {
        temp[i] = list->tab[i - 1];
        i++;
    }
    i = 0;
    while (i < list->size)
    {
        list->tab[i] = temp[i];
        i++;
    }
    if(m == 'a')
        write(1, "rra\n", 4);
    else if(m == 'b')
        write(1, "rrb\n", 4);
    free(temp);
}