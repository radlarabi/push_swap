/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:22:12 by rlarabi           #+#    #+#             */
/*   Updated: 2022/12/16 19:18:54 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_2(t_list *a)
{
    if(a->tab[a->top] > a->tab[a->top - 1])
        swap_list(a, 'a');
}

void sort_3(t_list *a)
{
    if (a->tab[0] > a->tab[1] && a->tab[0] > a->tab[2])
        swap_list(a, 'a');
    else if (a->tab[0] > a->tab[1] && a->tab[0] < a->tab[2])
        rotate_list(a, 'a');
    else if (a->tab[2] < a->tab[1] && a->tab[0] < a->tab[2])
        rotate_reverce_list(a, 'a');
    else if (a->tab[2] > a->tab[0] && a->tab[0] < a->tab[1])
    {
        swap_list(a, 'a');
        rotate_reverce_list(a, 'a');
    }
    else if (a->tab[1] > a->tab[0] && a->tab[0] > a->tab[2])
    {
        swap_list(a, 'a');
        rotate_list(a, 'a');
    }
}

int get_min(int *a, int size)
{
    int i = 0, j = 0, min = a[0];
    while (i <= size)
    {
        j = i + 1;
        while (j <= size)
        {
            if (min > a[j])
                min = a[j];
            j++;
        }
        i++;
    }
    return min;
} 
int get_index(int *a, int size,int i)
{
    int j = 0;
    while (j <= size && i != a[j])
        j++;
    return j;
}


void sort_5(t_list *a, t_list *b)
{
    int mid;
    int min;
    int index;
    int i;
    
    i = 0;
    while (i++ <= a->top)
    {
        mid = (int)a->top / 2;
        min = get_min(a->tab,a->top);
        index = get_index(a->tab, a->top, min);
        if (index > mid)
        {
            while(a->tab[a->top] != min)
                rotate_list(a, 'a');
        }
        else if (index <= mid)
        {
            while(a->tab[a->top] != min)
                rotate_reverce_list(a, 'a');
        }
        push(a, b, 'b');
    }
    i = b->top;
    while (i-- >= 0)
        push(b ,a , 'a');
}
