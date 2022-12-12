/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:38:23 by rlarabi           #+#    #+#             */
/*   Updated: 2022/12/12 13:50:20 by rlarabi          ###   ########.fr       */
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
}           t_list;
void        swap_list(t_list *list, char m);
void        rotate_list(t_list *list, char m);
void        display_list(t_list *a);
void    push_a(t_list *a, t_list *b);
void    push_b(t_list *a, t_list *b);
void    rotate_reverce_list(t_list *list, char m);
#endif