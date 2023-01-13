/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:38:23 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/11 14:54:47 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*tab;
	int	top;
}		t_list;

typedef struct s_table
{
	int	*array;
	int	start;
	int	end;
}		t_table;

/* operation */
void	swap_list(t_list *list, char m);
void	rotate_list(t_list *list, char m);
void	rotate_reverce_list(t_list *list, char m);
void	push(t_list *a, t_list *b, char m);

/* utiles */
int		is_duplicate(t_list *a);
int		get_min(int *a, int size);
t_list	*create_list(int i);
int		get_index(int *a, int size, int i);
int		is_sorted(t_list *a);
int		*get_table(t_list *a);
int		if_exist(t_list *a, int *arr, int start, int end);
int		get_max_list(int *a, int size);
int		is_duplicate(t_list *a);
int		is_sorted(t_list *a);
int		get_max_list_without(int *a, int size, int exept);
int		calcule_steps(t_list *a, int *array_sorted, int start, int end);
void	free_stacks(t_list *a, t_list *b);
int		check_args(int ac, char **av);
void	sub_push_a_b(t_list *a, int *array_sorted, int start, int end);
void	free_2d_table(char **t);
int		change_chunk_big(int start, int end, int size, char a);
int		sub_check_args(char *temp);
int		change_chunk_small(int start, int end, int size, char a);
int		ft_isdigit(int c);
char	**ft_split(char const *str, char set);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);

/* sort utiles */
void	sort_2(t_list *a);
void	sort_3(t_list *a);
void	sort_4(t_list *a, t_list *b);
void	sort_5(t_list *a, t_list *b);
void	small_sort(t_list *a, t_list *b);
void	big_sort(t_list *a, t_list *b);

#endif