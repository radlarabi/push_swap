/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:38:23 by rlarabi           #+#    #+#             */
/*   Updated: 2022/12/16 19:19:23 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_stack
{
    int     *tab;
    int     size;
    int     top;
}           t_list;

/* operation */
void        swap_list(t_list *list, char m);
void        rotate_list(t_list *list, char m);
void        rotate_reverce_list(t_list *list, char m);
void        push(t_list *a, t_list *b, char m);

/* utiles */
int         is_duplicate(t_list *a);
void        display_list(t_list *a);
int         get_min(int *a, int size);
t_list      *create_list(int i);
int         get_index(int *a, int size, int i);
int         get_median(t_list *a);
int         is_sorted(t_list *a);

/* sort utiles */
void        sort_2(t_list *a);
void        sort_3(t_list *a);
void        sort_5(t_list *a, t_list *b);
// void        small_sort(t_list *a, t_list *b);
// void        big_sort(t_list *a, t_list *b);

#endif