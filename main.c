/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:41:17 by rlarabi           #+#    #+#             */
/*   Updated: 2022/12/16 19:20:57 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_arg(char **ret)
{
    int i = 0, j = 0;
    while (ret[i])
    {
        j = 0;
        while(ret[i][j])
        {
            if (!ft_isdigit(ret[i][j]))
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
    int *temp;
    if (ac == 1)
        return 0;
    ret = ft_split(av[1], ' ');
    while(ret[i])
        i++;
    temp = malloc(sizeof(int) * i);
    a = create_list(i);
    b = create_list(i);
    while(i > 0)
    {
        if(!ft_atoi(ret[--i]) && ft_strncmp(ret[i],"0", 1))
        {
            write(1, "Error\n", 6);
            return 0;
        }
        a->tab[++a->top] = ft_atoi(ret[i]);
    }
    if(!is_duplicate(a))
    {
        write(1, "Error\n", 6);
        return 0;       
    }
    else if(is_sorted(a))
        return 0;
    else if (a->top == 1)
        sort_2(a);
    else if (a->top == 2)
        sort_3(a);
    else if (a->top == 4)
        sort_5(a, b);
    // else if (a->top > 4 && a->top <= 99)
    //     small_sort(a, b);
    // else if (a->top > 99)
    //     big_sort(a, b);


    
    display_list(b);
    return 0;
}
















































// int get_min_list(t_list *a)
// {
//     int min = a->tab[0], i = 0, j;
//     while(i < a->size)
//     {
//         j = 0;
//         while(j < a->size)
//         {
//             if(min > a->tab[j])
//                 min = a->tab[j];
//             j++;
//         }
//         i++;
//     }
//     return min;
// }
// int get_max_list(t_list *a)
// {
//     int max = a->tab[0], i = 0, j;
//     while(i < a->size)
//     {
//         j = 0;
//         while(j < a->size)
//         {
//             if(max < a->tab[j])
//                 max = a->tab[j];
//             j++;
//         }
//         i++;
//     }
//     return max;
// }
// int get_min(int *a, int start, int end)
// {
//     int i = start, min = a[start];
//     while (i < end)
//     {
//         if (min >  a[i])
//             min = a[i];
//         i++;   
//     }
//     return min;
// }
// void sort_4(t_list *a, t_list *b)
// {
//     int min = 0, mdl = 0, i = 0,j = 0, max, place_index = 0, temp = 0, size = a->size , t1;
//     while (!is_sorted(a))
//     {
//         j = 0;
//         while (j < a->size)
//         {
//             temp = j + 1;
//             if (a->tab[j] < a->tab[j + 1])
//             {
//                 j++;
//                 continue;
//             }
//             printf("---%d---\n", temp);
//             min = get_min(a->tab, j , a->size);
//             break;
//         }
//         mdl = (int) a->size / 2;
//         // break;
//         printf("min---%d---\n", min);
//         while (place_index < a->size)
//         {
//             if (a->tab[place_index] == min)
//                 break;
//             place_index++;
//         }
//         if (place_index <= mdl)
//         {
//             printf("up\n");
//         }
//         else
//             printf("down\n");
//         //printf("pi---%d---\n", place_index);
//         break;

//         // while (j >= 0)
//         // {
//         //     if (is_sorted(a))
//         //         break;
//         //     if (min == a->tab[0] && a->size != 1)
//         //     {
//         //         push_a(a, b);
//         //         t1 = 0;
//         //     }
//         //     else if (temp <= mdl && a->size != 1)
//         //     {
//         //         rotate_list(a, 'a');
                
//         //     }
//         //     else if (temp > mdl && a->size != 1)
//         //     {
//         //         rotate_reverce_list(a, 'a');
                
//         //     }
//         //     j--;
//         // }
//         // i++;
//     }
//     // i = b->size;
//     // while (i > 0)
//     // {
//     //     push_b(a, b);
//     //     i--;
//     // }
// }