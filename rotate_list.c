/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:19:39 by rlarabi           #+#    #+#             */
/*   Updated: 2022/12/11 20:23:54 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_list(t_list *list, char m)
{
    int i = 0;
    int *temp;

    temp = malloc(sizeof(int) * list->size);
    temp[list->size - 1] = list->tab[0];
    while (i < list->size - 1)
    {
        temp[i] = list->tab[i + 1];
        i++;
    }
    i = 0;
    while (i < list->size)
    {
        list->tab[i] = temp[i];
        i++;
    }
    if(m == 'a')
        write(1, "ra\n", 3);
    else if(m == 'b')
        write(1, "rb\n", 3);
    free(temp);
}