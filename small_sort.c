/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:11:56 by rlarabi           #+#    #+#             */
/*   Updated: 2022/12/20 15:42:36 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_grand(t_list *a, int i)
{
    int j = a->top;
    while (j >= 0)
    {
        if (a->tab[j] <= i)
            return 1;
        j--;
    }
    return 0;
}
int check_small(t_list *a, int i)
{
    int j = a->top;
    while (j >= 0)
    {
        if (a->tab[j] >= i)
            return 1;
        j--;
    }
    return 0;
}

int get_max_list(int *a, int size)
{
    int max = a[0], i = 0, j;
    while(i < size)
    {
        j = i + 1;
        while(j < size)
        {
            if(max < a[j])
                max = a[j];
            j++;
        }
        i++;
    }
    return max;
}
int get_max_whitout(int *a, int size, int non)
{
    int max = a[0], i = 0, j;
    while(i < size)
    {
        j = i + 1;
        while(j < size)
        {
            if (a[j] == non)
            {
                j++;
                continue;
            }
            if(max < a[j])
                max = a[j];
            j++;
        }
        i++;
    }
    return max;
}

// int if_exist(int *a, int size_a,int *array, int start , int end, int old_start , int old_end)
// {
//   int i = start, j = 0;
//   while (i <= end)
//   {
//     if (i >= old_start && i <= old_end)
//         i += (old_end - old_start) + 1;
//     j = 0;
//     while (j < size_a)
//     {
//       if (a[j] == array[i])
//         return 1;
//       j++;
//     }
//     i++;
//   }
//   return 0;
// }

int if_exist(int *a, int size_a , int * arr ,int start, int end, int t1, int t2)
{
    int i = start;
    while(i <= end)
    {
        if (i == t1)
            i += (t2 - t1) - 1;
        if (a[i] >= arr[start] && a[i] <= arr[end])
            return 1;
        i++;
    }
    return 0;
}
void small_sort(t_list *a, t_list *b)
{
    int *array_sorted = get_table(a);
    int median = get_median(a), mid = ((a->top + 1) / 2) - 1;
    int offset =  (a->top + 1) / 8 ,start = mid - offset, end= mid + offset, i = 0, j = 0, max, max2, t1 = 1, max_temp;

    while (a->top != -1)
    {
        while (if_exist(a->tab,array_sorted, start, end, i, j))
        {
            if (a->tab[a->top] >= array_sorted[start] && a->tab[a->top] <= array_sorted[end])    
            {
                push(a, b, 'b');
                // if(a->tab[a->top] > a->tab[a->top - 1])
                //     swap_list(a, 'a');
                if(b->tab[b->top] <= array_sorted[mid] && b->top != 0 && b->top != -1)
                    rotate_list(b , 'b');
            }
            else
            {
                i = 0;
                while(i <= a->top)
                {
                   if (a->tab[i] >= array_sorted[start] && a->tab[i] <= array_sorted[end])
                        break;
                    i++;
                }
                j = a->top;
                while(j >= 0)
                {
                   if (a->tab[j] >= array_sorted[start] && a->tab[j] <= array_sorted[end])
                        break;
                    j--;
                }
                if (i > a->top - j)
                    rotate_list(a, 'a');
                else
                    rotate_reverce_list(a, 'a');
            }
            i++;
        }
        i = start;
        j = end;
        start -= offset;
        end += offset;
    }
    i = b->top;
    max2 = get_max_list(b->tab, b->top + 1);
    while (i >= 0)
    {
        max = get_max_list(b->tab, b->top + 1);
        if (get_index(b->tab ,  b->top, max) > (b->top / 2))
        {
            max_temp = get_max_whitout(b->tab ,b->top + 1, max);
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














    // max = get_max_list(b->tab, b->top + 1);

    // while (a->tab[a->top] != max)
    // {
    //     if(b->tab[b->top] < b->tab[b->top - 1])
    //         swap_list(b, 'b');
    //     push(b, a, 'a');
    //     if(a->tab[a->top] > a->tab[a->top - 1])
    //         swap_list(a, 'a');
    //     i--;
    // }

    // while (i >= 0)
    // {
    //     max2 = get_max_list(b->tab, b->top + 1);
        
    //     if(b->tab[b->top] < b->tab[b->top - 1])
    //         swap_list(b, 'b');

    //     push(b, a, 'a');
        
    //     if(a->tab[a->top] > a->tab[a->top - 1])
    //         swap_list(a, 'a');
            
    //     if (a->tab[a->top] > max2)
    //     {
    //         rotate_list(a,'a');
    //         continue;
    //     }
    //     while (a->tab[0] != max)
    //         rotate_reverce_list(a, 'a');
    //     i--;
    // }












// i = b->top;
//     max = get_max_list(b->tab, b->top + 1);
//     while (a->tab[a->top] != max)
//     {
//         push(b, a, 'a');
//         i--;
//     }
//     while (a->tab[0] != max)
//         rotate_reverce_list(a, 'a');
//     while (i >= 0)
//     {
//         push(b, a, 'a');
//         max2 = get_max_list(b->tab, b->top + 1);
//         if (a->tab[a->top] < max2)
//         {
//             rotate_list(a,'a');
//             continue;
//         } 
//         while (a->tab[0] != max)
//             rotate_reverce_list(a, 'a');
//         i--;
//     }






















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
