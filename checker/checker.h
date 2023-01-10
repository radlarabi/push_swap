/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:52:02 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/10 12:39:02 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif
# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*tab;
	int	top;
}		t_list;

char	*get_next_line(int fd);
int		ret_line(char *str);
int		end_line(char *str);
char	*remplire_line(char *reserve);
char	*remplire(int fd, char *reserve);
char	*ft_update(char *reserve);
void	swap_list(t_list *list);
void	rotate_list(t_list *list);
void	rotate_reverce_list(t_list *list);
void	push(t_list *a, t_list *b);
char	*ft_strdup1(char *s1);
size_t	ft_strlen1(char *str);
t_list	*create_list(int i);
int		is_duplicate(t_list *a);
int		is_sorted(t_list *a);
int		check_args(int ac, char **av);
void	read_op1(t_list *a, t_list *b, char *temp);
int		read_op2(t_list *a, t_list *b, char *temp);
void	free_stacks(t_list *a, t_list *b);
void	init_stacks(t_list *a, t_list *b, int ac, char **av);
void	free_2d_table(char **t);
int		sub_check_args(char *temp);
#endif