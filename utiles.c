/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:13:10 by rlarabi           #+#    #+#             */
/*   Updated: 2022/12/16 15:09:12 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void display_list(t_list *a)
{
    int i = a->top;
    while(i >= 0)
    {
        printf("%d\n", a->tab[i]);
        i--;
    }
}

int is_duplicate(t_list *a)
{
   int i;
   int j;
   i = 0;
   while (i < a->size)
   {
        j = i + 1;
        while (j < a->size)
        {
            if (a->tab[i] == a->tab[j])
                return 0;
            j++;
        }
        i++;
   }
   return 1;
}

int is_sorted(t_list *a)
{
   int i;
   int j;
   i = a->top;
   while (i >= 0)
   {
        j = i - 1;
        while (j >= 0)
        {
            if (a->tab[i] > a->tab[j])
                return 0;
            j--;
        }
        i--;
   } 
   return 1;
}

t_list  *create_list(int i)
{
    t_list *a;
    a = malloc(sizeof(t_list));
    a->tab = malloc(sizeof(int) * i);
    a->size = 0; 
    a->top = -1; 
    return a;
}

int get_median(t_list *a)
{
    int i = 0, temp, j, median = 1, size = a->top + 1;
    int *array;
    if (a->top != -1)
        array = malloc(a->top * sizeof(int));
    while(i <= a->top)
    {
        array[i] = a->tab[i];
        i++;
    }
    while(i < size)
    {
        j = 0;
        while(j < size - 1)
        {
            if(array[j]>array[j+1])
            {
                temp        = array[j];
                array[j]    = array[j+1];
                array[j+1]  = temp;
            }
            j++;
        }
        i++;
    }
    if(size % 2 == 0)
        median = (array[(size-1)/2] + array[size/2]) / 2;
    else
        median = array[size / 2];
    return median;
}