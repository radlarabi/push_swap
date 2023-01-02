/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:41:17 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/02 17:01:11 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
int check_arg(char **ret, int ac)
{
    int i = 1, j = 0;
    while (i < ac)
    {
        j = 0;
        while(ret[i][j])
        {
            // printf("%d, %d, -> %c\n", i, j ,ret[i][j]);
            if (!ft_isdigit(ret[i][j]))
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}
void free_stack(t_list *a)
{
    free(a->tab);
    free(a);
}
int main(int ac, char **av)
{
    t_list *a, *b;
    char **ret;
    int i = 0;
    int *temp;
    if (ac == 1)
        return 0;
    
    if(ac == 2)
    {
        ret = ft_split(av[1], ' ');
        while (ret[i])
            i++;
        temp = malloc(sizeof(int) * i);
        a = create_list(i);
        b = create_list(i);
        while(i > 0)
        {
            if((ft_atoi(ret[--i]) >= INT_MAX) || (!ft_atoi(ret[i]) && ft_strncmp(ret[i],"0", 1)))
            {
                write(2, "Error\n", 6);
                return 0;
            }
            a->tab[++a->top] = ft_atoi(ret[i]);
        }
    }
    else if (ac > 2)
    {
        temp = malloc(sizeof(int) * (ac - 1));
        a = create_list(ac - 1);
        b = create_list(ac - 1);
        i = ac - 1;
        while (i > 0)
        {
            if(check_arg(av, ac) && !ft_atoi(av[i]) && ft_strncmp(av[i],"0", 1))
            {
                write(2, "Error\n", 6);
                return 0;
            }
            a->tab[++a->top] = ft_atoi(av[i]);
            i--;
        }
    }
    if(is_duplicate(a))
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
    else if (a->top == 3)
        sort_4(a, b);
    else if (a->top == 4)
        sort_5(a, b);
    else if (a->top > 4 && a->top <= 99)
        small_sort(a, b);
    else if (a->top > 99)
        big_sort(a, b);



    // display_list(a);
    // printf("-_-_-_-_\n");
    //display_list(a);
    free_stack(a);
    free_stack(b);
    return 0;
}


