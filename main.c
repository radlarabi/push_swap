/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:41:17 by rlarabi           #+#    #+#             */
/*   Updated: 2022/12/12 21:20:21 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void display_list(t_list *a)
{
    int i = 0;
    while(i < a->size)
    {
        printf("%d\n", a->tab[i]);
        i++;
    }
}
void sort_2(t_list *a, t_list *b)
{
    if(a->tab[0] > a->tab[1])
        swap_list(a, 'a');
}

void sort_3(t_list *a, t_list *b)
{
    if (a->tab[0] > a->tab[1] && a->tab[0] < a->tab[2])
        swap_list(a, 'a');
    else if (a->tab[0] > a->tab[2] && a->tab[1] < a->tab[2])
        rotate_list(a, 'a');
    else if (a->tab[2] > a->tab[0] && a->tab[0] < a->tab[1]
    && a->tab[2] < a->tab[1])
    {
        rotate_reverce_list(a, 'a');
        swap_list(a, 'a');
    }
    else if (a->tab[0] > a->tab[1] && a->tab[0] > a->tab[2])
    {
        rotate_list(a, 'a');
        swap_list(a, 'a');
    }
    else if (a->tab[2] < a->tab[1] && a->tab[0] > a->tab[2]
    && a->tab[1] > a->tab[0])
        rotate_reverce_list(a, 'a');
}
int get_min_list(t_list *a)
{
    int min = a->tab[0], i = 0, j;
    while(i < a->size)
    {
        j = 0;
        while(j < a->size)
        {
            if(min > a->tab[j])
                min = a->tab[j];
            j++;
        }
        i++;
    }
    return min;
}
int get_max_list(t_list *a)
{
    int max = a->tab[0], i = 0, j;
    while(i < a->size)
    {
        j = 0;
        while(j < a->size)
        {
            if(max < a->tab[j])
                max = a->tab[j];
            j++;
        }
        i++;
    }
    return max;
}
int is_sorted(t_list *a)
{
   int i;
   int j;
   i = 0;
   while (i < a->size)
   {
        j = 1;
        while (j < a->size)
        {
            if (a->tab[i] > a->tab[j])
                return 0;
            j++;
        }
        i++;
   } 
   return 1;
}
void sort_4(t_list *a, t_list *b)
{
    int min, mdl, i = 0,j = 0, max, temp = 0, size = a->size , t1;
    max = get_max_list(a);
    mdl = (int) a->size / 2;
    min = get_min_list(a);
    while (i < a->size + 7)
    {
        j = 0;
        min = get_min_list(a);
        mdl = (int) a->size / 2;
        while (j < a->size)
        {
            if(min == a->tab[j])
                temp = j;
            j++;      
        }
        j = temp;
        //printf("j : %d\n",j);
        while (j > 0)
        {
            if (temp <= mdl)
            {
                rotate_list(a, 'a');
            }
            else
            {
                rotate_reverce_list(a, 'a');
            }
            j--;
        }
        push_a(a, b);
        //printf("min : %d \t max : %d\t mdl : %d\n", min, max, mdl);
        i++;
    }
    i = b->size;
    while (i > 0)
    {
        //rotate_reverce_list(b, 'b');
        push_b(a, b);
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
int main(int ac, char **av)
{
    t_list *a, *b;
    char **ret;
    int i = 0;
    if (ac == 1)
        return 0;
    a = malloc(sizeof(t_list));
    a->tab = malloc(sizeof(int) * (ac - 1));

    b = malloc(sizeof(t_list));
    b->tab = malloc(sizeof(int) * (ac - 1));
    b->size = 0;
    ret = ft_split(av[1], ' ');
    while(ret[a->size])
        a->size += 1;
    while(i < a->size)
    {
        if(!ft_atoi(ret[i]))
        {
            write(1, "Error\n", 6);
            return 0; 
        }
        a->tab[i] = ft_atoi(ret[i]);
        i++;
    }
    if(!is_duplicate(a))
    {
        write(1, "Error\n", 6);
        return 0;       
    }
    // else if(is_sorted(a))
    //     return 0;
    // else if (a->size == 2)
    //     sort_2(a, b);
    // else if (a->size == 3)
    //     sort_3(a, b);
    // else if (a->size == 4)
    //sort_4(a, b);

    // push_b(a, b);
    // rotate_list(a, 'a');
    printf("snksnckodnsckod");
    b->size += 1;
    printf("\n----%d-----\n", b->size);
    b->tab[b->size - 1] = a->tab[0];

    //if (a->size != 0 && a->size != 1)
      //  rotate_list(a, 'a');
    //a->size -= 1;
   // write(1, "pa\n", 3);
        
    display_list(a);
    // display_list(a);
    // push_b(a, b);
    // display_list(a);
    //display_list(a);

    return 0;
}
