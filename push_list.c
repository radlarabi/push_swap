/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:11:01 by rlarabi           #+#    #+#             */
/*   Updated: 2022/12/12 20:19:31 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_a(t_list *a, t_list *b)
{
    if (a->size != 0)
    {
        b->size += 1;
        b->tab[b->size - 1] = a->tab[0];

        if (a->size != 0 && a->size != 1)
            rotate_list(a, 'a');
        a->size -= 1;
        write(1, "pa\n", 3);
    }
}


void    push_b(t_list *a, t_list *b)
{
    if (b->size != 0)
    {
        a->size += 1;
        a->tab[a->size - 1] = b->tab[0];
        if (a->size != 0 && a->size != 1)
            rotate_list(b, 'b');

        b->size -= 1;
        write(1, "pb\n", 3);
    }
    
}
