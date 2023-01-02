/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:12:26 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/02 16:35:56 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void big_sort(t_list *a, t_list *b)
{
    int *array_sorted = get_table(a);
    int mid = ((a->top + 1) / 2) - 1;
    int offset =  (a->top + 1) / 20 ,start = mid - offset, end= mid + offset, i = 0, j = 0, max, max2;

    while (a->top != -1)
    {
        while (if_exist(a->tab, a->top + 1,array_sorted, start, end))
        {
            if (a->tab[a->top] >= array_sorted[start] && a->tab[a->top] <= array_sorted[end])    
            {
                push(a, b, 'b');
                if(b->tab[b->top] <= array_sorted[mid] && b->top != 0 && b->top != -1)
                    rotate_list(b , 'b');
            }
            else
            {
                i = 0;
                while(i <= a->top / 2)
                {
                   if (a->tab[i] >= array_sorted[start] && a->tab[i] <= array_sorted[end])
                        break;
                    i++;
                }
                j = a->top;
                while(j / 2 >= 0)
                {
                   if (a->tab[j] >= array_sorted[start] && a->tab[j] <= array_sorted[end])
                        break;
                    j--;
                }
                if (i >= a->top - j)
                    rotate_list(a, 'a');
                else
                    rotate_reverce_list(a, 'a');
            }
        }
        start -= offset;
        end += offset;
    }
    i = b->top;
    j = 0;
    max2 = get_max_list(b->tab, b->top + 1);
    while (i >= 0)
    {
        max = get_max_list(b->tab, b->top + 1);
        if (get_index(b->tab ,  b->top, max) > (b->top / 2))
        {
            while (b->tab[b->top] != max)
                rotate_list(b, 'b');
        }
        else
        {
            while (b->tab[b->top] != max)
                rotate_reverce_list(b, 'b');
        }
        push(b, a, 'a');
        i--;
    }
}


