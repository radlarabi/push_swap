/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:11:56 by rlarabi           #+#    #+#             */
/*   Updated: 2022/12/18 14:55:05 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_grand(t_list *a, int i)
{
    int j = a->top;
    while (j >= 0)
    {
        if (a->tab[j] < i)
            return 0;
        j--;
    }
    return 1;
}
void small_sort(t_list *a, t_list *b)
{
    int mid,i = 0,j, median, index, start , end;
    t_table *temp;

    index = get_index(a->tab, a->top , median);
    temp = get_table(a);
    end = temp->end / 2;
    start = 0;
    while (j <= 10)
    {
        i = a->top;
        median = get_median(a);
        while (i >= 0)
        {
            if (check_grand(a, median) || is_sorted(a))
                break;
            else if (a->tab[a->top] > a->tab[a->top - 1] && a->tab[a->top - 1] > median)
                swap_list(a, 'a');
            else if(a->tab[a->top] < median)
                push(a, b, 'b');
            else if (a->tab[a->top] >= median && a->tab[0] < median)
                rotate_reverce_list(a, 'a');
            else
                rotate_list(a, 'a');
            if (b->tab[b->top] < b->tab[0] && b->tab[b->top] < b->tab[b->top - 1])
                rotate_list(b, 'b');
            else if (b->tab[b->top] < b->tab[b->top - 1])
                swap_list(b, 'b');
            if (a->top == 2)
                sort_3(a);
            i--;
            // printf("\n-_-_median %d-_-_\n", median);
            // display_list(a);
            // printf("\n-_-_-_-_\n");
            // display_list(b);
            // printf("\n-_-_-_-_\n");
        }
        j++;
    }
    j = b->top;
    while(j >= 0)
    {
        push(b, a, 'a');
        i = a->top;
        while (i >= 0)
        {
            if (a->tab[a->top - i] < a->tab[a->top])
            {
                index = get_index(a->tab, a->top, a->tab[a->top - i]);
                if (i == 1)
                    swap_list(a, 'a');
                if (i == 2)
                {
                    swap_list(a, 'a');
                    rotate_list(a, 'a');
                    swap_list(a, 'a');
                    rotate_reverce_list(a, 'a');
                }
                // if (index > (a->top / 2))
                //     printf("\n***%d***\n", index);
            }
            // break;
            i--;
        }
        j--;
        
        // printf("\n^^^^^^^^\n");
        // display_list(a);
    }
}




























// void small_sort(t_list *a, t_list *b)
// {
//     int mid,i = 0,j, median, index, start , end;
//     t_table *temp;

//     index = get_index(a->tab, a->top , median);
//     temp = get_table(a);
//     end = temp->end / 2;
//     start = 0;
//     while (j <= 10)
//     {
//         i = a->top;
//         median = get_median(a);
//         while (i >= 0)
//         {
//             if (check_grand(a, median) || is_sorted(a))
//                 break;
//             else if (a->tab[a->top] > a->tab[a->top - 1] && a->tab[a->top - 1] > median)
//                 swap_list(a, 'a');
//             else if(a->tab[a->top] < median)
//                 push(a, b, 'b');
//             else if (a->tab[a->top] >= median && a->tab[0] < median)
//                 rotate_reverce_list(a, 'a');
//             else
//                 rotate_list(a, 'a');
//             if (b->tab[b->top] < b->tab[0] && b->tab[b->top] < b->tab[b->top - 1])
//                 rotate_list(b, 'b');
//             else if (b->tab[b->top] < b->tab[b->top - 1])
//                 swap_list(b, 'b');
//             if (a->top == 2)
//                 sort_3(a);
//             i--;
//             // printf("\n-_-_median %d-_-_\n", median);
//             // display_list(a);
//             // printf("\n-_-_-_-_\n");
//             // display_list(b);
//             // printf("\n-_-_-_-_\n");
//         }
//         j++;
//     }
//     j = b->top;
//     while(j >= 0)
//     {
//         push(b, a, 'a');
//         i = a->top;
//         while (i >= 0)
//         {
//             if (a->tab[a->top - i] < a->tab[a->top])
//             {
//                 index = get_index(a->tab, a->top, a->tab[a->top - i]);
//                 if (i == 1)
//                     swap_list(a, 'a');
//                 if (i == 2)
//                 {
//                     swap_list(a, 'a');
//                     rotate_list(a, 'a');
//                     swap_list(a, 'a');
//                     rotate_reverce_list(a, 'a');
//                 }
//                 // if (index > (a->top / 2))
//                 //     printf("\n***%d***\n", index);
//             }
//             // break;
//             i--;
//         }
//         j--;
        
//         // printf("\n^^^^^^^^\n");
//         // display_list(a);
//     }
// }