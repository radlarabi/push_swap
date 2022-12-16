/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:47:08 by rlarabi           #+#    #+#             */
/*   Updated: 2022/12/16 19:12:55 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_list(t_list *list, char m)
{
    int temp, top = list->top;
    temp = list->tab[top];
    list->tab[top] = list->tab[top - 1];
    list->tab[top - 1] = temp;

    if (m == 'a')
        write(1, "sa\n", 3);
    else if (m == 'b')
        write(1, "sb\n", 3);
}

void    push(t_list *a, t_list *b, char m)
{
    b->tab[++b->top] = a->tab[a->top--];
    if (m == 'a')
        write(1, "pa\n", 3);
    else if (m == 'b')
        write(1, "pb\n", 3);
}

void    rotate_reverce_list(t_list *list, char m)
{
    int i = 0;
    int *temp;
    
    if (list->top != -1)
    {
        temp = malloc(sizeof(int) * list->top);
        temp[list->top] = list->tab[0];
        while (i < list->top)
        {
            temp[i] = list->tab[i + 1];
            i++;
        }
        i = 0;
        while (i <= list->top)
        {
            list->tab[i] = temp[i];
            i++;
        }
        if(m == 'a')
            write(1, "rra\n", 4);
        else if(m == 'b')
            write(1, "rrb\n", 4);
        //free(temp);
    }
}

void    rotate_list(t_list *list, char m)
{
    int i = 1;
    int *temp;
    if (list->top != -1)
    {
        temp = malloc(sizeof(int) * list->top);
        temp[0] = list->tab[list->top];
        while (i <= list->top)
        {
            temp[i] = list->tab[i - 1];
            i++;
        }
        i = 0;
        while (i <= list->top)
        {
            list->tab[i] = temp[i];
            i++;
        }
        if(m == 'a')
            write(1, "ra\n", 3);
        else if(m == 'b')
            write(1, "rb\n", 3);
        //free(temp);
    }
}